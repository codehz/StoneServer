#include "common.h"
#include <interface/chat.h>
#include <stone-api/Script.h>

namespace ExtAPI {
using namespace interface;
using namespace api;

static void broadcastExternalEventCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 2) {
    iso->ThrowException(Exception::TypeError(ToJS(strformat("broadcastExternalEvent requires 2 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsString() || !info[1]->IsString()) {
    iso->ThrowException(Exception::TypeError(ToJS("broadcastExternalEvent requires (string, string)")));
    return;
  }
  auto identify = fromJS<std::string>(iso, info[0]);
  auto content  = fromJS<std::string>(iso, info[1]);
  Locator<ScriptService<ServerSide>>()->broadcast << EventData{ identify, content };
}

static Register reg{ "registerComponent", "broadcastExternalEvent", &broadcastExternalEventCallback };

} // namespace ExtAPI