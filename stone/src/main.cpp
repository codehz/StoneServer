#include <hybris/dlfcn.h>
#include <log.h>
#include <mcpelauncher/app_platform.h>
#include <mcpelauncher/crash_handler.h>
#include <mcpelauncher/minecraft_utils.h>
#include <mcpelauncher/mod_loader.h>
#include <minecraft/AppResourceLoader.h>
#include <minecraft/AutomationClient.h>
#include <minecraft/Common.h>
#include <minecraft/DedicatedServerCommandOrigin.h>
#include <minecraft/ExternalFileLevelStorageSource.h>
#include <minecraft/FilePathManager.h>
#include <minecraft/I18n.h>
#include <minecraft/LevelSettings.h>
#include <minecraft/Minecraft.h>
#include <minecraft/MinecraftCommands.h>
#include <minecraft/MinecraftEventing.h>
#include <minecraft/PermissionsMap.h>
#include <minecraft/ResourcePack.h>
#include <minecraft/ResourcePackStack.h>
#include <minecraft/SaveTransactionManager.h>
#include <minecraft/ServerInstance.h>
#include <minecraft/Whitelist.h>

#define SIMPPL_HAVE_INTROSPECTION true
#include <simppl/dispatcher.h>
#include <simppl/skeleton.h>
#include <simppl/string.h>
#include <simppl/stub.h>

#include <stone/utils.h>
#include <uintl.h>

#include <condition_variable>
#include <csignal>
#include <mutex>

#include "server_minecraft_app.h"
#include "server_properties.h"
#include "services.h"
#include "stub_key_provider.h"

#ifndef BUILD_VERSION
#define BUILD_VERSION "UNKNOWN VERSION"
#endif

#define LOAD_ENV(env, def) const auto env = GetEnvironmentVariableOrDefault(#env, def)

void hack(void *handle, char const *symbol) {
  void *ptr = hybris_dlsym(handle, symbol);
  PatchUtils::patchCallInstruction(ptr, (void *)(void (*)())[]{}, true);
}

int main() {
  using namespace uintl;
  using namespace simppl::dbus;
  using namespace one::codehz::stone;
  CrashHandler::registerCrashHandler();
  MinecraftUtils::workaroundLocaleBug();
  MinecraftUtils::setMallocZero();
  auto cwd = PathHelper::getWorkingDir();
  PathHelper::setGameDir(cwd + "game/");
  PathHelper::setDataDir(cwd + "data/");
  PathHelper::setCacheDir(cwd + "cache/");
  Log::getLogLevelString(LogLevel::LOG_TRACE); // Generate level string cache
  Log::info("StoneServer", "StoneServer (version: %s)", BUILD_VERSION);

  MinecraftUtils::setupForHeadless();

  Log::trace("StoneServer", "Loading Minecraft library");
  void *handle = MinecraftUtils::loadMinecraftLib();
  Log::info("StoneServer", "Loaded Minecraft library");
  Log::debug("StoneServer", "Minecraft is at offset 0x%x", MinecraftUtils::getLibraryBase(handle));

  MinecraftUtils::initSymbolBindings(handle);
  Log::info("StoneServer", "Game version: %s", Common::getGameVersionStringNet().c_str());

  Log::info("StoneServer", "Applying patches");
  hack(handle, "_ZN5Level17_checkUserStorageEv");
  *reinterpret_cast<void **>(hybris_dlsym(handle, "_ZN6RakNet19rakDebugLogCallbackE")) = nullptr;

  ModLoader modLoader;
  modLoader.loadModsFromDirectory(PathHelper::getPrimaryDataDirectory() + "mods/");

  Log::trace("StoneServer", "Initializing AppPlatform (vtable)");
  LauncherAppPlatform::initVtable(handle);
  Log::trace("StoneServer", "Initializing AppPlatform (create instance)");
  std::unique_ptr<LauncherAppPlatform> appPlatform(new LauncherAppPlatform());
  // Try to use i18n
  *(reinterpret_cast<mcpe::string *>(appPlatform.get()) + sizeof(AppPlatform) / sizeof(void *)) = "en_US"_static_intl;
  Log::trace("StoneServer", "Initializing AppPlatform (initialize call)");
  appPlatform->initialize();

  Log::trace("StoneServer", "Loading server properties");
  ServerProperties props;
  props.load();

  Log::trace("StoneServer", "Loading whitelist and operator list");
  Whitelist whitelist;
  PermissionsMap permissionsMap(true);

  Log::trace("StoneServer", "Setting up level settings");
  LevelSettings levelSettings;
  levelSettings.seed                 = LevelSettings::parseSeedString(props.worldSeed.get(), Level::createRandomSeed());
  levelSettings.gametype             = props.gamemode;
  levelSettings.forceGameType        = props.forceGamemode;
  levelSettings.difficulty           = props.difficulty;
  levelSettings.dimension            = 0;
  levelSettings.generator            = props.worldGenerator;
  levelSettings.edu                  = false;
  levelSettings.mpGame               = true;
  levelSettings.lanBroadcast         = true;
  levelSettings.commandsEnabled      = true;
  levelSettings.texturepacksRequired = false;
  levelSettings.defaultSpawnX        = INT_MIN;
  levelSettings.defaultSpawnY        = INT_MIN;
  levelSettings.defaultSpawnZ        = INT_MIN;

  Log::trace("StoneServer", "Initializing FilePathManager");
  FilePathManager pathmgr(appPlatform->getCurrentStoragePath(), false);
  pathmgr.setPackagePath(appPlatform->getPackagePath());
  pathmgr.setSettingsPath(pathmgr.getRootPath());
  Log::trace("StoneServer", "Initializing resource loaders");
  ResourceLoaders::registerLoader((ResourceFileSystem)1,
                                  std::unique_ptr<ResourceLoader>(new AppResourceLoader([&pathmgr] { return pathmgr.getPackagePath(); })));
  ResourceLoaders::registerLoader((ResourceFileSystem)8,
                                  std::unique_ptr<ResourceLoader>(new AppResourceLoader([&pathmgr] { return pathmgr.getUserDataPath(); })));
  ResourceLoaders::registerLoader((ResourceFileSystem)4,
                                  std::unique_ptr<ResourceLoader>(new AppResourceLoader([&pathmgr] { return pathmgr.getSettingsPath(); })));

  Log::trace("StoneServer", "Initializing MinecraftEventing (create instance)");
  MinecraftEventing eventing(pathmgr.getRootPath());
  Log::trace("StoneServer", "Initializing MinecraftEventing (init call)");
  eventing.init();
  Log::trace("StoneServer", "Initializing ResourcePackManager");
  ContentTierManager ctm;
  ResourcePackManager *resourcePackManager = new ResourcePackManager([&pathmgr]() { return pathmgr.getRootPath(); }, ctm);
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
  std::shared_ptr<SaveTransactionManager> saveTransactionManager(new SaveTransactionManager([](bool b) {
    if (b)
      Log::debug("StoneServer", "Saving the world...");
    else
      Log::debug("StoneServer", "World has been saved.");
  }));
  Log::debug("StoneServer", "Initializing ExternalFileLevelStorageSource");
  ExternalFileLevelStorageSource levelStorage(&pathmgr, saveTransactionManager);
  Log::debug("StoneServer", "Initializing ServerInstance");
  auto idleTimeout                 = std::chrono::seconds((int)(props.playerIdleTimeout * 60.f));
  IContentKeyProvider *keyProvider = &stubKeyProvider;
  auto createLevelStorageFunc      = [&levelStorage, &props, keyProvider](Scheduler &scheduler) {
    return levelStorage.createLevelStorage(scheduler, props.worldDir.get(), *ContentIdentity::EMPTY, *keyProvider);
  };
  std::unique_ptr<EducationOptions> eduOptions(new EducationOptions(resourcePackManager));
  ServerInstance instance(minecraftApp, whitelist, permissionsMap, &pathmgr, idleTimeout, props.worldDir.get(), props.worldName.get(),
                          props.motd.get(), levelSettings, props.viewDistance, true, props.port, props.portV6, props.maxPlayers, props.onlineMode, {},
                          "normal", *mce::UUID::EMPTY, eventing, resourcePackRepo, ctm, *resourcePackManager, createLevelStorageFunc,
                          pathmgr.getWorldsPath(), nullptr, mcpe::string(), mcpe::string(), std::move(eduOptions), nullptr,
                          [](mcpe::string const &s) { Log::debug("StoneServer", "Unloading level: %s", s.c_str()); },
                          [](mcpe::string const &s) { Log::debug("StoneServer", "Saving level: %s", s.c_str()); });
  Log::trace("StoneServer", "Loading language data");
  I18n::loadLanguages(*resourcePackManager, "en_US"_static_intl);
  resourcePackManager->onLanguageChanged();
  Log::info("StoneServer", "Server initialized");
  modLoader.onServerInstanceInitialized(&instance);

  LOAD_ENV(TARGET_BUS, "bus:session");
  Log::trace("StoneServer", "Initializing rpc (%s)", TARGET_BUS.c_str());
  Dispatcher disp(TARGET_BUS.c_str());
  static Dispatcher *pdisp = &disp;

  Skeleton<CoreService> srv_core(disp, "daemon");
  srv_core.stop >> [&] {
    srv_core.respond_with(srv_core.stop());
    disp.stop();
  };
  Skeleton<CommandService> srv_command(disp, "daemon");
  srv_command.execute >> [&](std::string const &origin, std::string const &command) {
    auto ret = EvalInServerThread<std::string>(instance, [&] {
      std::unique_ptr<DedicatedServerCommandOrigin> commandOrigin(new DedicatedServerCommandOrigin(origin, *instance.minecraft));
      instance.minecraft->getCommands()->requestCommandExecution(std::move(commandOrigin), command, 4, true);
      return origin + ": " + command;
    });
    srv_command.respond_with(srv_command.execute(ret));
  };

  std::signal(SIGINT, [](int) { pdisp->stop(); });

  Log::trace("StoneServer", "Starting server thread");
  instance.startServerThread();
  Log::info("StoneServer", "Server is running");
  disp.run();

  Log::info("StoneServer", "Server is stopping");
  instance.leaveGameSync();

  MinecraftUtils::workaroundShutdownCrash(handle);
  Log::info("StoneServer", "Server stopped");
  pdisp = nullptr;
  return 0;
}