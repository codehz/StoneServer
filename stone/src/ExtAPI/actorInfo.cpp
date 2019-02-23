#include "common.h"

namespace ExtAPI {

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
  temp->Set(strName, ToJS(actor->getNameTag().std()));
  temp->Set(strIdentifier, ToJS(actor->getActorIdentifier().getCanonicalName().std()));
  temp->Set(strPos, ToJS(actor->getPos()));
  auto [did] = actor->getDimensionId();
  temp->Set(strDim, ToJS(did));
  info.GetReturnValue().Set(temp);
}

static Register reg{ "registerComponent", "actorInfo", &actorInfoCallback };

}; // namespace ExtAPI