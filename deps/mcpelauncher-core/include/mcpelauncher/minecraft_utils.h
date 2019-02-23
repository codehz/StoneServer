#pragma once

#include <mcpelauncher/path_helper.h>

class MinecraftUtils {

private:
    static void* loadLibM();

    static void setupHookApi();

public:
    static void workaroundLocaleBug();

    static void setMallocZero();

    static void setupHybris();

    static void* loadMinecraftLib(std::string const& path = PathHelper::findGameFile("libs/libminecraftpe.so"));

    static void* loadFMod();
    static void stubFMod();

    static void setupForHeadless();

    static unsigned int getLibraryBase(void* handle);

    static void initSymbolBindings(void* handle);

    static void workaroundShutdownCrash(void* handle);

};
