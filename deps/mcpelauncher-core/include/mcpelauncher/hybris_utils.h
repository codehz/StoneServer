#pragma once

#include <string>

class HybrisUtils {

private:
    static const char* TAG;

public:
    static bool loadLibrary(std::string path);
    static void* loadLibraryOS(std::string path, const char** symbols);

    static void stubSymbols(const char** symbols, void* stubfunc);

private:
    friend class MinecraftUtils;

    static void hookAndroidLog();

};