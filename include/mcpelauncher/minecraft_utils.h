#pragma once

class MinecraftUtils {

private:
    static void* loadLibM();

public:
    static void setupHybris();

    static void* loadMinecraftLib();

    static void* loadFMod();
    static void stubFMod();

    static unsigned int getLibraryBase(void* handle);

    static void workaroundShutdownCrash(void* handle);

};