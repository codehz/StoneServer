#include "common.h"
#include <interface/chat.h>

namespace ExtAPI {
using namespace interface;

static void broadcastMessageCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 1) {
    iso->ThrowException(Exception::TypeError(STR(strformat("broadcastMessage requires 1 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsString()) {
    iso->ThrowException(Exception::TypeError(STR("broadcastMessage requires (string)")));
    return;
  }
  auto content = fromJS<std::string>(iso, info[0]);
  Locator<Chat>()->sendAnnouncement(content);
}

static Register reg{ "registerComponent", "broadcastMessage", &broadcastMessageCallback };

} // namespace ExtAPI