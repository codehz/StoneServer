#include "common.h"
#include <interface/chat.h>

#include "../custom_command.h"

namespace ExtAPI {
using namespace interface;

static void currentCommandOriginCallback(FunctionCallbackInfo<Value> const &info) {
  if (current_orig) {
    auto iso                = info.GetIsolate();
    auto temp               = Object::New(iso);
    // auto strName            = toJS<std::string>(iso, "name");
    // auto strBlockPos        = toJS<std::string>(iso, "blockPos");
    // auto strWorldPos        = toJS<std::string>(iso, "worldPos");
    // auto strEntity          = toJS<std::string>(iso, "entity");
    // auto strPermissionLevel = toJS<std::string>(iso, "permissionLevel");
    // temp->Set(strName, toJS<std::string>(iso, current_orig->getName().std()));
    // temp->Set(strBlockPos, toJS(iso, current_orig->getBlockPosition()));
    // temp->Set(strWorldPos, toJS(iso, current_orig->getWorldPosition()));
    // temp->Set(strEntity, toJS(iso, current_orig->getEntity()));
    // temp->Set(strPermissionLevel, toJS(iso, current_orig->getPermissionLevel()));
    info.GetReturnValue().Set(temp);
  }
}

static Register reg{ "registerComponent", "currentCommandOrigin", &currentCommandOriginCallback };

} // namespace ExtAPI