#include "common.h"
#include <interface/chat.h>

#include "../custom_command.h"

namespace ExtAPI {
using namespace interface;

static void muteChatCallback(FunctionCallbackInfo<Value> const &info) {
  Locator<Chat>()->intercept = !(info.Length() > 0 && info[0]->IsFalse());
}

static Register reg{ "registerComponent", "muteChat", &muteChatCallback };

} // namespace ExtAPI