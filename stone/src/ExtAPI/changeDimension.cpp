#include "common.h"

namespace ExtAPI {
using namespace patched;

static void changeDimensionCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 2) {
    iso->ThrowException(Exception::TypeError(ToJS(strformat("changeDimension requires 2 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsObject() || !info[1]->IsNumber()) {
    iso->ThrowException(Exception::TypeError(ToJS("changeDimension requires (object, number)")));
    return;
  }
  Actor *actor = fromJS<Actor *>(iso, info[0]);
  if (!actor) {
    iso->ThrowException(Exception::TypeError(ToJS("changeDimension requires (actor, number)")));
    return;
  }
  actor->changeDimension(fromJS<int>(iso, info[1]), false);
}
static Register reg{ "registerComponent", "changeDimension", &changeDimensionCallback };
} // namespace ExtAPI