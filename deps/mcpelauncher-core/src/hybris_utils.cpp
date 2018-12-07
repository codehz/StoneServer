#include <mcpelauncher/hybris_utils.h>
#include <mcpelauncher/path_helper.h>
#include <log.h>
#include <hybris/hook.h>
#include <hybris/dlfcn.h>

const char* HybrisUtils::TAG = "HybrisUtils";


bool HybrisUtils::loadLibrary(std::string path) {
    void* handle = hybris_dlopen(PathHelper::findDataFile("libs/hybris/" + path).c_str(), RTLD_LAZY);
    if (handle == nullptr) {
        Log::error(TAG, "Failed to load hybris library %s: %s", path.c_str(), hybris_dlerror());
        return false;
    }
    return true;
}

void* HybrisUtils::loadLibraryOS(std::string path, const char** symbols) {
    void* handle = dlopen(path.c_str(), RTLD_LAZY);
    if (handle == nullptr) {
        Log::error(TAG, "Failed to load OS library %s", path.c_str());
        return nullptr;
    }
    Log::trace(TAG, "Loaded OS library %s", path.c_str());
    int i = 0;
    while (true) {
        const char* sym = symbols[i];
        if (sym == nullptr)
            break;
        void* ptr = dlsym(handle, sym);
        hybris_hook(sym, ptr);
        i++;
    }
    return handle;
}

void HybrisUtils::stubSymbols(const char** symbols, void* stubfunc) {
    int i = 0;
    while (true) {
        const char* sym = symbols[i];
        if (sym == nullptr)
            break;
        hybris_hook(sym, stubfunc);
        i++;
    }
}