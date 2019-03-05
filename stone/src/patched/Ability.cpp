#include "../patched.h"

#include <interface/locator.hpp>
#include <interface/policy.h>
#include <minecraft/GameMode.h>

#include "HardcodedOffsets.h"

#include <stone/server_hook.h>

namespace {
using namespace interface;
using namespace patched;

SHook(bool, _ZN6Player13canUseAbilityERKSs, Player *player, mcpe::string const &ability) {
  bool result = original(player, ability);
  Locator<Policy>()->checkAbility(player, ability.std(), result);
  return result;
}

SInstanceHook(bool, _ZN8GameMode12destroyBlockERK8BlockPosa, GameMode, BlockPos const &pos, signed char data) {
  bool result = original(this, pos, data);
  Locator<Policy>()->checkDestroy(this->player, pos, result);
  return result;
}

SInstanceHook(bool, _ZN8GameMode10buildBlockERK8BlockPosa, GameMode, BlockPos const &pos, signed char data) {
  bool result = original(this, pos, data);
  Locator<Policy>()->checkBuild(this->player, pos, result);
  return result;
}

SInstanceHook(bool, _ZN8GameMode7useItemER12ItemInstance, GameMode, ItemInstance &instance) {
  bool result = original(this, instance);
  Locator<Policy>()->checkUse(this->player, instance, result);
  return result;
}

SInstanceHook(bool, _ZN8GameMode9useItemOnER12ItemInstanceRK8BlockPosaRK4Vec3, GameMode, ItemInstance &instance, BlockPos const &pos,
              signed char data, Vec3 const &vec) {
  bool result = original(this, instance, pos, data, vec);
  Locator<Policy>()->checkUseOn(this->player, instance, pos, vec, result);
  return result;
}

SInstanceHook(bool, _ZN8GameMode8interactER5ActorRK4Vec3, GameMode, Actor &target, Vec3 const &pos) {
  bool result = original(this, target, pos);
  Locator<Policy>()->checkInteract(this->player, target, pos, result);
  return result;
}

SInstanceHook(bool, _ZN8GameMode6attackER5Actor, GameMode, Actor &target) {
  bool result = original(this, target);
  Locator<Policy>()->checkAttack(this->player, target, result);
  return result;
}

static patched::details::RegisterPatchInit pinit([] { Locator<Policy>().generate(); });

} // namespace