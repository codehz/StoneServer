#include "../patched.h"

#include <interface/locator.hpp>
#include <interface/policy.h>

#include <stone/server_hook.h>

namespace {
using namespace interface;

SHook(bool, _ZN6Player13canUseAbilityERKSs, Player *player, mcpe::string const &ability) {
  bool result = original(player, ability);
  Locator<Policy>()->checkAbility(player, ability.std(), result);
  return result;
}

static patched::details::RegisterPatchInit pinit([] { Locator<Policy>().generate(); });

} // namespace