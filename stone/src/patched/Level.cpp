#include "../patched.h"

#include <interface/locator.hpp>
#include <interface/tick.h>
#include <stone/server_hook.h>

#include <minecraft/Level.h>
#include <minecraft/ServerCommandOrigin.h>

#include "../server_properties.h"

#include <time.h>

namespace {
using namespace interface;

SInstanceHook(int, _ZN11ServerLevel10initializeERKSsRK13LevelSettingsP9LevelData, ServerLevel, void *a, void *b, void *c) {
  Locator<ServerLevel>() = this;
  return original(this, a, b, c);
}

SInstanceHook(void, _ZN5Level4tickEv, Level) {
  static auto last  = clock();
  static auto flame = 0;
  flame++;
  Locator<Tick>()->tick();
  if (auto now = clock(); now - last > CLOCKS_PER_SEC) {
    Locator<Tick>()->tps = flame;

    flame = 0;
    last  = now;
  }
  original(this);
}

static patched::details::RegisterPatchInit pinit([] { Locator<Tick>().generate(); });

} // namespace