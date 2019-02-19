#include "common.h"
#include <interface/chat.h>

#include "../custom_command.h"

namespace ExtAPI {
using namespace interface;

static void currentCommandOriginCallback(FunctionCallbackInfo<Value> const &info) {
  if (current_orig) {
    auto iso                = info.GetIsolate();
    auto temp               = Object::New(iso);
    auto strName            = ToJS("name");
    auto strBlockPos        = ToJS("blockPos");
    auto strWorldPos        = ToJS("worldPos");
    auto strEntity          = ToJS("entity");
    auto strPermissionLevel = ToJS("permissionLevel");
    temp->Set(strName, ToJS(current_orig->getName().std()));
    temp->Set(strBlockPos, ToJS(current_orig->getBlockPosition()));
    temp->Set(strWorldPos, ToJS(current_orig->getWorldPosition()));
    temp->Set(strEntity, ToJS(current_orig->getEntity()));
    temp->Set(strPermissionLevel, ToJS(current_orig->getPermissionLevel()));
    info.GetReturnValue().Set(temp);
  }
}

static Register reg{ "registerComponent", "currentCommandOrigin", &currentCommandOriginCallback };

} // namespace ExtAPI