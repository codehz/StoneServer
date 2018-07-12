#include <log.h>
#include <mcpelauncher/minecraft_utils.h>
#include <mcpelauncher/crash_handler.h>
#include <minecraft/Common.h>
#include <mcpelauncher/app_platform.h>
#include <hybris/dlfcn.h>

int main(int argc, char *argv[]) {
    CrashHandler::registerCrashHandler();
    MinecraftUtils::workaroundLocaleBug();
    PathHelper::setGameDir(argv[1]);

    MinecraftUtils::setupForHeadless();

    Log::trace("Launcher", "Loading Minecraft library");
    void* handle = MinecraftUtils::loadMinecraftLib();
    Log::info("Launcher", "Loaded Minecraft library");
    Log::debug("Launcher", "Minecraft is at offset 0x%x", MinecraftUtils::getLibraryBase(handle));

    MinecraftUtils::initSymbolBindings(handle);
    Log::info("Launcher", "Game version: %s", Common::getGameVersionStringNet().c_str());

    Log::trace("Launcher", "Loading user library");
    void* userHandle = hybris_dlopen(argv[2], RTLD_LAZY);
    Log::debug("Launcher", "User library is at offset 0x%x", MinecraftUtils::getLibraryBase(userHandle));

    Log::trace("Launcher", "Initializing AppPlatform (vtable)");
    LauncherAppPlatform::initVtable(handle);
    Log::trace("Launcher", "Initializing AppPlatform (create instance)");
    LauncherAppPlatform* appPlatform = new LauncherAppPlatform();
    Log::trace("Launcher", "Initializing AppPlatform (initialize call)");
    appPlatform->initialize();

    void (*mcmain)(void*) = (void (*)(void*)) hybris_dlsym(userHandle, "mcmain");
    mcmain(appPlatform);

    MinecraftUtils::workaroundShutdownCrash(handle);
    return 0;
}