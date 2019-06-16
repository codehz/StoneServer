#include <hybris/dlfcn.h>
#include <log.h>
#include <mcpelauncher/app_platform.h>
#include <mcpelauncher/crash_handler.h>
#include <mcpelauncher/minecraft_utils.h>
#include <mcpelauncher/mod_loader.h>
#include <minecraft/AppResourceLoader.h>
#include <minecraft/AutomationClient.h>
#include <minecraft/CommandRegistry.h>
#include <minecraft/Common.h>
#include <minecraft/ExternalFileLevelStorageSource.h>
#include <minecraft/FilePathManager.h>
#include <minecraft/I18n.h>
#include <minecraft/LevelSettings.h>
#include <minecraft/Minecraft.h>
#include <minecraft/MinecraftCommands.h>
#include <minecraft/MinecraftEventing.h>
#include <minecraft/PermissionsFile.h>
#include <minecraft/ResourcePack.h>
#include <minecraft/ResourcePackStack.h>
#include <minecraft/SaveTransactionManager.h>
#include <minecraft/ServerCommandOrigin.h>
#include <minecraft/ServerInstance.h>
#include <minecraft/TextPacket.h>
#include <minecraft/Whitelist.h>

#include <stone/hook_helper.h>
#include <stone/server_hook.h>
#include <stone/symbol.h>
#include <stone/utils.h>

#include <interface/chat.h>
#include <interface/locator.hpp>
#include <interface/player_list.h>
#include <interface/tick.h>

#include <stone-api/Blacklist.h>
#include <stone-api/Chat.h>
#include <stone-api/Command.h>
#include <stone-api/Core.h>
#include <stone-api/Script.h>

#include <condition_variable>
#include <csignal>
#include <mutex>

#include "blacklist_mgr.hpp"
#include "patched.h"
#include "patched/HardcodedOffsets.h"
#include "server_minecraft_app.h"
#include "server_properties.h"
#include "stub_key_provider.h"
#include "v8_platform.h"
#include "whitelist_mgr.hpp"

#include <stone/version.h>

#define LOAD_ENV(env, def) static const auto env = GetEnvironmentVariableOrDefault(#env, def)

void hack(void *handle, char const *symbol) {
  void *ptr = hybris_dlsym(handle, symbol);
  PatchUtils::patchCallInstruction(ptr, (void *)(void (*)())[]{}, true);
}

LOAD_ENV(API_ENDPOINT, "ws+unix://data/api.socket");

void initDependencies();

void rakDebugLog(char const *format, ...) {
  char *cpd = strdup(format);
  if (format[0]) { cpd[strlen(cpd) - 1] = 0; }
  va_list args;
  va_start(args, format);
  Log::vlog(LogLevel::LOG_TRACE, "RakNet", cpd, args);
  va_end(args);
  free(cpd);
}

int main() {
  using namespace interface;
  using namespace std;
  using namespace api;

  const clock_t start_clock = clock();

  if (getenv("STONE_DEBUG")) Log::MIN_LEVEL = LogLevel::LOG_TRACE;

  initDependencies();

  CrashHandler::registerCrashHandler();
  MinecraftUtils::workaroundLocaleBug();
  MinecraftUtils::setMallocZero();

  auto cwd = PathHelper::getWorkingDir();
  PathHelper::setGameDir(cwd + "game/");
  PathHelper::setDataDir(cwd + "data/");
  PathHelper::setCacheDir(cwd + "cache/");
  Log::getLogLevelString(LogLevel::LOG_TRACE); // Generate level string cache
  Log::info("StoneServer", "StoneServer (version: %s)", build_version);

  MinecraftUtils::setupForHeadless();

  Log::trace("StoneServer", "Loading Minecraft library");
  const clock_t loading_library = clock();
  void *handle = MinecraftHandle() = MinecraftUtils::loadMinecraftLib();
  Log::info("StoneServer", "Loaded Minecraft library in %f sec.", float(clock() - loading_library) / CLOCKS_PER_SEC);
  Log::debug("StoneServer", "Minecraft is at offset 0x%x", MinecraftUtils::getLibraryBase(handle));

  static const auto ep = std::make_shared<epoll>();
  endpoint() = std::make_unique<rpcws::RPC>(std::make_unique<rpcws::server_wsio>(API_ENDPOINT, ep));

  auto &srv_core [[maybe_unused]]      = Locator<CoreService>().generate();
  auto &srv_chat [[maybe_unused]]      = Locator<ChatService>().generate();
  auto &srv_blacklist [[maybe_unused]] = Locator<BlacklistService>().generate();
  auto &srv_command [[maybe_unused]]   = Locator<CommandService>().generate();
  auto &srv_script [[maybe_unused]]    = Locator<ScriptService>().generate();
  Log::addHook([&](auto level, auto tag, auto content) { srv_core.log << LogEntry{ tag, level, content }; });

  MinecraftUtils::initSymbolBindings(handle);
  Log::info("StoneServer", "Game version: %s", Common::getGameVersionStringNet().c_str());

  Log::info("StoneServer", "Applying patches");
  hack(handle, "_ZN5Level17_checkUserStorageEv");
  *reinterpret_cast<bool *>(hybris_dlsym(handle, "_ZN10BedrockLog15gLogFileCreatedE")) = true;
  *reinterpret_cast<void **>(hybris_dlsym(handle, "_ZN6RakNet19rakDebugLogCallbackE")) = (void *)&rakDebugLog;
  RegisterServerHook::InitHooks();

  ModLoader modLoader;
  modLoader.loadModsFromDirectory(PathHelper::getPrimaryDataDirectory() + "mods/");

  Log::trace("StoneServer", "Initializing AppPlatform (vtable)");
  LauncherAppPlatform::initVtable(handle);
  Log::trace("StoneServer", "Initializing AppPlatform (create instance)");
  auto appPlatform = make_unique<LauncherAppPlatform>();
  // Try to use i18n
  *(reinterpret_cast<mcpe::string *>(appPlatform.get()) + sizeof(AppPlatform) / sizeof(void *)) = "en_US";
  Log::trace("StoneServer", "Initializing AppPlatform (initialize call)");
  appPlatform->initialize();

  Log::trace("StoneServer", "Loading server properties");
  auto &props = Locator<ServerProperties>().generate();
  props.load();
  srv_core.config >> [cfg = props.config](auto) { return cfg; };
  Log::info("StoneServer", "Config: %s", props.config.c_str());

  Log::trace("StoneServer", "Setting up level settings");
  LevelSettings levelSettings;
  levelSettings.seed                  = LevelSettings::parseSeedString(props.worldSeed.get(), Level::createRandomSeed());
  levelSettings.gametype              = props.gamemode;
  levelSettings.forceGameType         = props.forceGamemode;
  levelSettings.difficulty            = props.difficulty;
  levelSettings.dimension             = 0;
  levelSettings.generator             = props.worldGenerator;
  levelSettings.edu                   = props.eduMode;
  levelSettings.eduFeatures           = props.eduMode;
  levelSettings.experimentalGameplay  = props.experimentMode;
  levelSettings.mpGame                = true;
  levelSettings.lanBroadcast          = true;
  levelSettings.xblBroadcast          = true;
  levelSettings.xblBroadcastIntent    = true;
  levelSettings.commandsEnabled       = props.cheatsEnabled;
  levelSettings.texturepacksRequired  = props.texturepackRequired;
  levelSettings.defaultSpawnX         = INT_MIN;
  levelSettings.defaultSpawnY         = INT_MIN;
  levelSettings.defaultSpawnZ         = INT_MIN;
  levelSettings.serverChunkTickRange  = props.tickDistance;
  levelSettings.overrideSavedSettings = props.overrideSavedSettings;
  levelSettings.achievementsDisabled  = false;
  if (props.experimentMode) Log::warn("StoneServer", "Experiment mode is enabled in config file!");

  Log::trace("StoneServer", "Initializing FilePathManager");
  FilePathManager pathmgr(appPlatform->getCurrentStoragePath(), false);
  pathmgr.setPackagePath(appPlatform->getPackagePath());
  pathmgr.setSettingsPath(pathmgr.getRootPath());

  Log::trace("StoneServer", "Loading whitelist, blacklist and operator list");
  auto &whitelist = Locator<WhitelistManager>().generate(pathmgr.getWorldsPath().std() + props.worldDir.get() + "/whitelist.json");
  Locator<BlacklistManager>().generate(pathmgr.getWorldsPath().std() + props.worldDir.get() + "/blacklist.json");
  PermissionsFile permissionsFile(pathmgr.getWorldsPath().std() + props.worldDir.get() + "/permissions.json");

  Log::trace("StoneServer", "Initializing resource loaders");
  ResourceLoaders::registerLoader((ResourceFileSystem)1, std::make_unique<AppResourceLoader>([&pathmgr] { return pathmgr.getPackagePath(); }));
  ResourceLoaders::registerLoader((ResourceFileSystem)8, std::make_unique<AppResourceLoader>([&pathmgr] { return pathmgr.getUserDataPath(); }));
  ResourceLoaders::registerLoader((ResourceFileSystem)4, std::make_unique<AppResourceLoader>([&pathmgr] { return pathmgr.getSettingsPath(); }));

  Log::trace("StoneServer", "Initializing MinecraftEventing (create instance)");
  MinecraftEventing eventing(pathmgr.getRootPath());
  Log::trace("StoneServer", "Initializing MinecraftEventing (init call)");
  eventing.init();
  Log::trace("StoneServer", "Initializing ResourcePackManager");
  ContentTierManager ctm;
  ResourcePackManager *resourcePackManager = new ResourcePackManager([&pathmgr]() { return pathmgr.getRootPath(); }, ctm, false);
  resourcePackManager->setExperimental(true);
  ResourceLoaders::registerLoader((ResourceFileSystem)0, std::unique_ptr<ResourceLoader>(resourcePackManager));
  Log::trace("StoneServer", "Initializing PackManifestFactory");
  PackManifestFactory packManifestFactory(eventing);
  Log::trace("StoneServer", "Initializing SkinPackKeyProvider");
  SkinPackKeyProvider skinPackKeyProvider;
  Log::trace("StoneServer", "Initializing StubKeyProvider");
  StubKeyProvider stubKeyProvider;
  Log::trace("StoneServer", "Initializing PackSourceFactory");
  PackSourceFactory packSourceFactory(nullptr);
  Log::trace("StoneServer", "Initializing ResourcePackRepository");
  ResourcePackRepository resourcePackRepo(eventing, packManifestFactory, skinPackKeyProvider, &pathmgr, packSourceFactory, false);
  Log::trace("StoneServer", "Adding vanilla resource pack");
  std::unique_ptr<ResourcePackStack> stack(new ResourcePackStack());
  stack->add(PackInstance(resourcePackRepo.vanillaPack, -1, false, nullptr), resourcePackRepo, false);
  resourcePackManager->setStack(std::move(stack), (ResourcePackStackType)3, false);
  Log::trace("StoneServer", "Adding world resource packs");
  resourcePackRepo.addWorldResourcePacks(pathmgr.getWorldsPath().std() + props.worldDir.get());
  resourcePackRepo.refreshPacks();
  Log::trace("StoneServer", "Initializing Automation::AutomationClient");
  DedicatedServerMinecraftApp minecraftApp;
  Automation::AutomationClient aclient(minecraftApp);
  minecraftApp.automationClient = &aclient;
  Log::debug("StoneServer", "Initializing SaveTransactionManager");
  auto saveTransactionManager = std::make_shared<SaveTransactionManager>([](bool b) {
    if (b)
      Log::debug("StoneServer", "Saving the world...");
    else
      Log::debug("StoneServer", "World has been saved.");
  });
  Log::debug("StoneServer", "Initializing ExternalFileLevelStorageSource");
  ExternalFileLevelStorageSource levelStorage(&pathmgr, saveTransactionManager);
  Log::debug("StoneServer", "Initializing ServerInstance");
  auto idleTimeout            = std::chrono::seconds((int)(props.playerIdleTimeout * 60.f));
  auto createLevelStorageFunc = [&](Scheduler &scheduler) {
    return levelStorage.createLevelStorage(scheduler, props.worldDir.get(), *ContentIdentity::EMPTY, stubKeyProvider);
  };
  auto eduOptions = std::make_unique<EducationOptions>(resourcePackManager);
  ServerInstanceEventCoordinator ec;
  auto instance = new ServerInstance(minecraftApp, ec);
  LauncherV8Platform::initVtable(handle);
  LauncherV8Platform v8Platform;
  v8::V8::InitializePlatform((v8::Platform *)&v8Platform);
  v8::V8::Initialize();
  Log::trace("StoneServer", "Initializing Server");
  instance->initializeServer(
      minecraftApp, whitelist.list, &permissionsFile, &pathmgr, idleTimeout, props.worldDir.get(), props.worldName.get(), props.motd.get(),
      levelSettings, props.viewDistance, true, { props.port, props.portV6, props.maxPlayers }, props.onlineMode, {}, "normal", *mce::UUID::EMPTY,
      eventing, resourcePackRepo, ctm, *resourcePackManager, createLevelStorageFunc, pathmgr.getWorldsPath(), nullptr, "boom", "test",
      std::move(eduOptions), nullptr, [](mcpe::string const &s) { Log::debug("Minecraft", "Unloading level: %s", s.c_str()); },
      [](mcpe::string const &s) { Log::debug("Minecraft", "Saving level: %s", s.c_str()); }, nullptr, nullptr);
  Locator<ServerInstance>() = instance;
  if (props.activateWhitelist) {
    Locator<Minecraft>()->activateWhitelist();
    Log::info("StoneServer", "Whitelist activated");
  }
  Log::trace("StoneServer", "Loading language data");
  ResourceLoadManager resLoadMgr;
  I18n::loadLanguages(*resourcePackManager, resLoadMgr, "en_US");
  resLoadMgr.sync((ResourceLoadType)4);
  resourcePackManager->onLanguageChanged();
  Log::info("StoneServer", "Server initialized");
  modLoader.onServerInstanceInitialized(instance);
  patched::init();

  Log::trace("StoneServer", "Starting server thread");
  instance->startServerThread();
  Log::info("StoneServer", "Server is running (%f sec)", float(clock() - start_clock) / CLOCKS_PER_SEC);

  std::signal(SIGINT, [](int) { endpoint()->stop(); ep->shutdown(); });
  std::signal(SIGTERM, [](int) { endpoint()->stop(); ep->shutdown(); });
  srv_core.stop >> [](auto) { endpoint()->stop(); ep->shutdown(); };
  srv_core.ping >> [](auto) {
    Log::info("API", "PING!");
    return Empty{};
  };
  srv_core.tps >> [](auto) { return Locator<Tick>()->tps; };
  srv_command.execute >> [](auto request) {
    return EvalInServerThread([&] {
      return patched::withCommandOutput([&] {
        auto commandOrigin = make_unique<ServerCommandOrigin>(request.sender, *Locator<ServerLevel>());
        Locator<MinecraftCommands>()->requestCommandExecution(std::move(commandOrigin), request.content, 4, true);
      });
    });
  };

  chdir((pathmgr.getWorldsPath().std() + props.worldDir.get()).c_str());

  if (getenv("UPSTART_JOB")) kill(getpid(), SIGSTOP);

  endpoint()->start();
  ep->wait();

  Log::info("StoneServer", "Server is stopping");
  patched::dest();
  instance->leaveGameSync();
  delete instance;
  appPlatform->teardown();

  MinecraftUtils::workaroundShutdownCrash(handle);
  Log::info("StoneServer", "Server stopped");
  Log::clearHooks();
  return 0;
}
