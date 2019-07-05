#include "../custom_command.h"
#include "common.h"
#include <interface/tick.h>
#include <epoll.hpp>

namespace ExtAPI {
using namespace interface;
using namespace patched;

static void stopCallback(FunctionCallbackInfo<Value> const &info) {
  Locator<epoll>()->shutdown();
}

static Register reg{ "registerComponent", "stop", &stopCallback };

} // namespace ExtAPI