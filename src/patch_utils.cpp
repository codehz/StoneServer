#include <mcpelauncher/patch_utils.h>

#include <log.h>
#include <cstring>
#include <hybris/dlfcn.h>

const char* PatchUtils::TAG = "Patch";

void PatchUtils::patchCallInstruction(void* patchOff, void* func, bool jump) {
    unsigned char* data = (unsigned char*) patchOff;
#ifdef __arm__
    if (!jump)
      throw std::runtime_error("Non-jump patches not supported in ARM mode");
    bool thumb = ((size_t) patchOff) & 1;
    if (thumb)
      data--;
    Log::trace(TAG, "Patching - original: %i %i %i %i %i", data[0], data[1], data[2], data[3], data[4]);
    if (thumb) {
        unsigned char patch[4] = {0xdf, 0xf8, 0x00, 0xf0};
        memcpy(data, patch, 4);
    } else {
        unsigned char patch[4] = {0x04, 0xf0, 0x1f, 0xe5};
        memcpy(data, patch, 4);
    }
    memcpy(&data[4], &func, sizeof(int));
    Log::trace(TAG, "Patching - result: %i %i %i %i %i", data[0], data[1], data[2], data[3], data[4]);
#else
    Log::trace(TAG, "Patching - original: %i %i %i %i %i", data[0], data[1], data[2], data[3], data[4]);
    data[0] = (unsigned char) (jump ? 0xe9 : 0xe8);
    int ptr = ((int) func) - (int) patchOff - 5;
    memcpy(&data[1], &ptr, sizeof(int));
    Log::trace(TAG, "Patching - result: %i %i %i %i %i", data[0], data[1], data[2], data[3], data[4]);
#endif
}

void PatchUtils::VtableReplaceHelper::replace(const char* name, void* replacement) {
    replace(hybris_dlsym(lib, name), replacement);
}

void PatchUtils::VtableReplaceHelper::replace(void* sym, void* replacement) {
    for (int i = 0; ; i++) {
        if (referenceVtable[i] == nullptr)
            break;
        if (referenceVtable[i] == sym) {
            vtable[i] = replacement;
            return;
        }
    }
}

size_t PatchUtils::getVtableSize(void** vtable) {
    for (size_t size = 2; ; size++) {
        if (vtable[size] == nullptr)
            return size;
    }
}