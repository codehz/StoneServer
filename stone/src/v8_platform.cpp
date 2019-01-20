#include "v8_platform.h"

#include <chrono>
#include <condition_variable>
#include <cstring>
#include <functional>
#include <hybris/dlfcn.h>
#include <interface/locator.hpp>
#include <log.h>
#include <mcpelauncher/patch_utils.h>
#include <minecraft/ServerInstance.h>
#include <mutex>
#include <queue>
#include <stone/server_hook.h>
#include <thread>

using namespace std::chrono_literals;

static class TaskRunner {
  std::thread thread;
  std::mutex m;
  std::condition_variable cv;
  std::queue<v8::Task *> tasks;
  bool stop = false;

  void loop() {
    std::queue<v8::Task *> temp;
    while (true) {
      {
        std::unique_lock<std::mutex> lk(m);
        cv.wait_for(lk, 10s);
        if (stop) return;
        if (tasks.empty()) continue;
        std::swap(temp, tasks);
      }
      while (!temp.empty()) {
        temp.front()->Run();
        temp.pop();
      }
    }
  }

public:
  TaskRunner()
      : thread(std::bind(&TaskRunner::loop, this)) {}

  void dispose() {
    if (stop) return;
    {
      std::unique_lock<std::mutex> lk(m);
      stop = true;
    }
    cv.notify_all();
    thread.join();
  }

  ~TaskRunner() { dispose(); }

  void operator()(v8::Task *task) {
    {
      std::unique_lock<std::mutex> lk(m);
      tasks.push(task);
    }
    cv.notify_one();
  }
} taskRunner;

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

SHook(void, _ZN9ScriptApi15V8CoreInterface8shutdownERNS_12ScriptReportE) {}

LauncherV8Platform::LauncherV8Platform() { vtable = myVtable; }

void LauncherV8Platform::CallOnBackgroundThread(v8::Task *task, v8::ExpectedRuntime expected_runtime) {
  // Log::warn("LauncherV8Platform", "CallOnBackgroundThread\n");
  taskRunner(task);
}

void LauncherV8Platform::CallOnForegroundThread(v8::Isolate *isolate, v8::Task *task) {
  using namespace interface;
  Log::warn("LauncherV8Platform", "CallOnForegroundThread\n");
  Locator<ServerInstance>()->queueForServerThread([=] { task->Run(); });
}

void LauncherV8Platform::CallDelayedOnForegroundThread(v8::Isolate *isolate, v8::Task *task, double delay_in_seconds) {
  Log::warn("LauncherV8Platform", "CallDelayedOnForegroundThread\n");
}

void LauncherV8Platform::CallIdleOnForegroundThread(v8::Isolate *isolate, v8::IdleTask *task) {
  Log::warn("LauncherV8Platform", "CallIdleOnForegroundThread\n");
}

bool LauncherV8Platform::IdleTasksEnabled(v8::Isolate *) { return false; }
