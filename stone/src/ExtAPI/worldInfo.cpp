#include "common.h"
#include <minecraft/Level.h>

namespace ExtAPI {
using namespace patched;

static void worldInfoCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };

  auto temp          = Object::New(iso);
  auto strSpawnPoint = ToJS("spawnPoint");
  temp->Set(strSpawnPoint, ToJS(Locator<Level>()->getDefaultSpawn()));
  info.GetReturnValue().Set(temp);
}

static Register reg{ "registerComponent", "worldInfo", &worldInfoCallback };

} // namespace ExtAPI