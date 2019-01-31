#include "../patched.h"

#include <minecraft/CommandOrigin.h>

#include <interface/locator.hpp>
#include <stone/server_hook.h>

#include "../server_properties.h"

namespace patched::flags {
bool CommandPrivileged = false;
}

namespace {

using namespace patched::flags;

SClasslessInstanceHook(int, _ZNK19PlayerCommandOrigin19getPermissionsLevelEv) {
  if (CommandPrivileged) return 4;
  return original(this);
}

} // namespace