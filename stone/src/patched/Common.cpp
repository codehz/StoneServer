#include "../patched.h"

#include <interface/locator.hpp>
#include <stone/server_hook.h>
#include <minecraft/Common.h>

namespace {

SStaticHook(mcpe::string, _ZN6Common23getGameVersionStringNetEv, Common) {
  return original() + "." + getGameDevVersionString();
}

} // namespace