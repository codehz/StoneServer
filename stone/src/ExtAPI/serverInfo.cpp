#include "../custom_command.h"
#include "common.h"
#include <interface/tick.h>

namespace ExtAPI {
using namespace interface;
using namespace patched;

static void severInfoCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };

  auto temp   = Object::New(iso);
  auto strTPS = ToJS("tps");
  temp->Set(strTPS, ToJS(Locator<Tick>()->tps));
  info.GetReturnValue().Set(temp);
}

static Register reg{ "registerComponent", "severInfo", &severInfoCallback };

} // namespace ExtAPI