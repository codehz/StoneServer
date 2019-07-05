#include "../custom_command.h"
#include "common.h"
#include <interface/tick.h>
#include <signal.h>
#include <unistd.h>

namespace ExtAPI {
using namespace interface;
using namespace patched;

static void stopCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  kill(getpid(), SIGTERM);
  info.GetReturnValue().Set(Undefined(iso));
}

static Register reg{ "registerComponent", "stop", &stopCallback };

} // namespace ExtAPI