#pragma once

class MinecraftUtils {

private:
    static void* loadLibM();

public:
    static void workaroundLocaleBug();

    static void setupHybris();

    static void* loadMinecraftLib();

    static void* loadFMod();
    static void stubFMod();

    static void setupForHeadless();

    static unsigned int getLibraryBase(void* handle);

    static void initSymbolBindings(void* handle);

    static void workaroundShutdownCrash(void* handle);

};