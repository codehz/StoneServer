#include "v8_platform.h"

#include <cstring>
#include <hybris/dlfcn.h>
#include <log.h>
#include <mcpelauncher/patch_utils.h>

void **LauncherV8Platform::myVtable;

void LauncherV8Platform::initVtable(void *lib) {
  void **vta          = &((void **)hybris_dlsym(lib, "_ZTVN6cohtml6script17ScriptingPlatformE"))[2];
  size_t myVtableSize = PatchUtils::getVtableSize(vta);
  Log::trace("LauncherV8Platform", "Vtable size = %u", myVtableSize);

  myVtable               = (void **)::operator new((myVtableSize + 1) * sizeof(void *));
  myVtable[myVtableSize] = nullptr;
  memcpy(&myVtable[0], &vta[0], myVtableSize * sizeof(void *));

  PatchUtils::VtableReplaceHelper vtr(lib, myVtable, vta);
  vtr.replace("_ZN6cohtml6script17ScriptingPlatform22CallOnBackgroundThreadEPN2v84TaskENS2_8Platform15ExpectedRuntimeE",
              &LauncherV8Platform::CallOnBackgroundThread);
  vtr.replace("_ZN6cohtml6script17ScriptingPlatform22CallOnForegroundThreadEPN2v87IsolateEPNS2_4TaskE", &LauncherV8Platform::CallOnForegroundThread);
  vtr.replace("_ZN6cohtml6script17ScriptingPlatform29CallDelayedOnForegroundThreadEPN2v87IsolateEPNS2_4TaskEd",
              &LauncherV8Platform::CallDelayedOnForegroundThread);
  vtr.replace("_ZN6cohtml6script17ScriptingPlatform26CallIdleOnForegroundThreadEPN2v87IsolateEPNS2_8IdleTaskE",
              &LauncherV8Platform::CallIdleOnForegroundThread);
  vtr.replace("_ZN6cohtml6script17ScriptingPlatform16IdleTasksEnabledEPN2v87IsolateE", &LauncherV8Platform::IdleTasksEnabled);
}

LauncherV8Platform::LauncherV8Platform() { vtable = myVtable; }

void LauncherV8Platform::CallOnBackgroundThread(v8::Task *task, v8::ExpectedRuntime expected_runtime) {
  Log::warn("LauncherV8Platform", "CallOnBackgroundThread\n");
  task->Run();
}

void LauncherV8Platform::CallOnForegroundThread(v8::Isolate *isolate, v8::Task *task) { Log::warn("LauncherV8Platform", "CallOnForegroundThread\n"); }

void LauncherV8Platform::CallDelayedOnForegroundThread(v8::Isolate *isolate, v8::Task *task, double delay_in_seconds) {
  Log::warn("LauncherV8Platform", "CallDelayedOnForegroundThread\n");
}

void LauncherV8Platform::CallIdleOnForegroundThread(v8::Isolate *isolate, v8::IdleTask *task) {}

bool LauncherV8Platform::IdleTasksEnabled(v8::Isolate *) { return false; }
