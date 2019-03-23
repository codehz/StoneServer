#include "../dumper.h"
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

SInstanceHook(bool, _ZN8GameMode12destroyBlockERK8BlockPosh, GameMode, BlockPos const &pos, unsigned char data) {
  bool result = true;
  Locator<Policy>()->checkDestroy(this->player, pos, result);
  if (result) return original(this, pos, data);
  return false;
}

SInstanceHook(bool, _ZN8GameMode10buildBlockERK8BlockPosh, GameMode, BlockPos const &pos, unsigned char data) {
  bool result = true;
  Locator<Policy>()->checkBuild(this->player, pos, result);
  if (result) return original(this, pos, data);
  return false;
}

SInstanceHook(bool, _ZN8GameMode7useItemER9ItemStack, GameMode, ItemStack &instance) {
  bool result = true;
  Locator<Policy>()->checkUse(this->player, instance, result);
  if (result) return original(this, instance);
  return false;
}

SInstanceHook(bool, _ZN8GameMode9useItemOnER9ItemStackRK8BlockPoshRK4Vec3PK5Block, GameMode, ItemStack &instance, BlockPos const &pos,
              unsigned char data, Vec3 const &vec, Block *block) {
  bool result = true;
  Locator<Policy>()->checkUseOn(this->player, instance, pos, vec, *block, result);
  if (result) original(this, instance, pos, data, vec, block);
  return false;
}

SInstanceHook(bool, _ZN8GameMode8interactER5ActorRK4Vec3, GameMode, Actor &target, Vec3 const &pos) {
  bool result = true;
  Locator<Policy>()->checkInteract(this->player, target, pos, result);
  if (result) original(this, target, pos);
  return false;
}

SInstanceHook(bool, _ZN8GameMode6attackER5Actor, GameMode, Actor &target) {
  bool result = true;
  Locator<Policy>()->checkAttack(this->player, target, result);
  if (result) original(this, target);
  return false;
}

SInstanceHook(bool, _ZNK5Block3useER6PlayerRK8BlockPos, Block, Player *player, BlockPos const &pos) {
  bool result = true;
  Locator<Policy>()->checkUseBlock(player, *this, pos, result);
  if (result) return original(this, player, pos);
  return false;
}

static patched::details::RegisterPatchInit pinit([] { Locator<Policy>().generate(); });

} // namespace