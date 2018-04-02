#pragma once

class MinecraftUtils {

public:
    static void* loadLibM();

    static void setupHybris();

    static void workaroundShutdownCrash(void* handle);

};