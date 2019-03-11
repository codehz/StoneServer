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
  using namespace std::chrono;
  using hrc             = std::chrono::high_resolution_clock;
  static auto start     = hrc::now();
  auto end              = hrc::now();
  long int frametime_us = (std::chrono::duration_cast<milliseconds>(end - start).count());
  start = end;
  Locator<Tick>()->tick();
  Locator<Tick>()->tps = (float)duration_cast<milliseconds>(1s).count() / frametime_us;
  original(this);
}

static patched::details::RegisterPatchInit pinit([] { Locator<Tick>().generate(); });

} // namespace