#include "common.h"
#include <interface/chat.h>

namespace ExtAPI {
using namespace interface;

static void broadcastMessageCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  if (info.Length() != 1) {
    Log::error("Scripting", "broadcastMessage requires 1 arguments(current: %d)", info.Length());
    return;
  }
  if (!info[0]->IsString()) {
    Log::error("Scripting", "broadcastMessage requires (string)");
    return;
  }
  auto content = fromJS<std::string>(iso, info[0]);
  Locator<Chat>()->sendAnnouncement(content);
}

static Register reg{ "registerComponent", "broadcastMessage", &broadcastMessageCallback };

} // namespace ExtAPI