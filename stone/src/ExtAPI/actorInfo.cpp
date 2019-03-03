#include "../patched/HardcodedOffsets.h"
#include "common.h"

namespace ExtAPI {
using namespace patched;

static void actorInfoCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 1) {
    iso->ThrowException(Exception::TypeError(ToJS(strformat("actorInfo requires 1 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsObject()) {
    iso->ThrowException(Exception::TypeError(ToJS("actorInfo requires (object)")));
    return;
  }
  Actor *actor = fromJS<Actor *>(iso, info[0]);
  if (!actor) {
    iso->ThrowException(Exception::TypeError(ToJS("actorInfo requires (actor)")));
    return;
  }
  auto temp          = Object::New(iso);
  auto strName       = ToJS("name");
  auto strIdentifier = ToJS("identifier");
  auto strPos        = ToJS("pos");
  auto strDim        = ToJS("dim");
  auto strUUID       = ToJS("uuid");
  auto strXUID       = ToJS("xuid");
  auto strPermission = ToJS("permission");
  temp->Set(strName, ToJS(actor->getNameTag().std()));
  temp->Set(strIdentifier, ToJS(actor->getActorIdentifier().getCanonicalName().std()));
  temp->Set(strPos, ToJS(actor->getPos()));
  auto [did] = actor->getDimensionId();
  temp->Set(strDim, ToJS(did));
  if (*(void **)actor == BUILD_HELPER(GetAddress, void, 0x8, "_ZTV12ServerPlayer").Address()) {
    auto player = (Player *)actor;
    temp->Set(strUUID, ToJS((*player) >> PlayerUUID >> UUIDStr >> StdStr));
    temp->Set(strXUID, ToJS((*player) >> PlayerXUID >> StdStr));
    temp->Set(strPermission, ToJS(player->getCommandPermissionLevel()));
  }
  info.GetReturnValue().Set(temp);
}

static Register reg{ "registerComponent", "actorInfo", &actorInfoCallback };

}; // namespace ExtAPI