#include <mcpelauncher/minecraft_utils.h>
#include <mcpelauncher/patch_utils.h>
#include <mcpelauncher/hybris_utils.h>
#include <log.h>
#include <hybris/dlfcn.h>

void MinecraftUtils::setupCommonMinecraftSymbols() {
    HybrisUtils::hookAndroidLog();
}

static void workerPoolDestroy(void* th) {
    Log::trace("Launcher", "WorkerPool-related class destroy %uli", (unsigned long) th);
}
void MinecraftUtils::workaroundShutdownCrash(void* handle) {
    // this is an ugly hack to workaround the close app crashes MCPE causes
    unsigned int patchOff = (unsigned int) hybris_dlsym(handle, "_ZN9TaskGroupD2Ev");
    PatchUtils::patchCallInstruction((void*) patchOff, (void*) &workerPoolDestroy, true);
    patchOff = (unsigned int) hybris_dlsym(handle, "_ZN10WorkerPoolD2Ev");
    PatchUtils::patchCallInstruction((void*) patchOff, (void*) &workerPoolDestroy, true);
    patchOff = (unsigned int) hybris_dlsym(handle, "_ZN9SchedulerD2Ev");
    PatchUtils::patchCallInstruction((void*) patchOff, (void*) &workerPoolDestroy, true);
}
