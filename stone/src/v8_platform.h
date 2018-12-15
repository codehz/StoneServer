#include <minecraft/V8.h>

class LauncherV8Platform {

private:
  static void **myVtable;

  void *vtable;
  char filler[0x100];

public:
  static void initVtable(void *lib);

  LauncherV8Platform();

  void CallOnBackgroundThread(v8::Task *task, v8::ExpectedRuntime expected_runtime);
  void CallOnForegroundThread(v8::Isolate *isolate, v8::Task *task);
  void CallDelayedOnForegroundThread(v8::Isolate *isolate, v8::Task *task, double delay_in_seconds);
  void CallIdleOnForegroundThread(v8::Isolate *isolate, v8::IdleTask *task);
  bool IdleTasksEnabled(v8::Isolate *);
  // double MonotonicallyIncreasingTime();
};