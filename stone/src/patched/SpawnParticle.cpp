#include "../patched.h"

#include "../dumper.h"
#include <minecraft/Level.h>
#include <stone/server_hook.h>

namespace {

SHook(void, _ZN5Level19spawnParticleEffectERKSsRK4Vec3P9Dimension, Level *self, mcpe::string const &name, Vec3 const &pos, void *dim) {
  if (self && dim) return original(self, name, pos, dim);
}

} // namespace