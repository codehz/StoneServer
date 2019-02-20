#include "common.h"
#include <interface/chat.h>

#include <minecraft/Actor.h>
#include <minecraft/Tag.h>

#include "../custom_command.h"

namespace ExtAPI {
using namespace interface;

static void loadTagCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() == 1 && info[0]->IsObject()) {
    auto actor   = fromJS<Actor *>(iso, info[0]);
    if (!actor) {
      iso->ThrowException(Exception::TypeError(ToJS("loadTag requires (actor)")));
      return;
    }
    CompoundTag compound;
    if (!actor->save(compound)) {
      iso->ThrowException(Exception::ReferenceError(ToJS("This actor don't have any tag")));
      return;
    }
    info.GetReturnValue().Set(toJS<CompoundTag const &>(iso, compound));
  } else {
    iso->ThrowException(Exception::TypeError(ToJS("loadTag requires (object)")));
  }
}

static Register reg{ "registerComponent", "loadTag", &loadTagCallback };

} // namespace ExtAPI