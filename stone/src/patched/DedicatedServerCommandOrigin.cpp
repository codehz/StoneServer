#include "../patched.h"

#include <minecraft/DedicatedServerCommandOrigin.h>

#include <interface/locator.hpp>
#include <stone/server_hook.h>

#include "../server_properties.h"

namespace {

SInstanceHook(mcpe::string, _ZNK28DedicatedServerCommandOrigin7getNameEv, DedicatedServerCommandOrigin) { return name; }

} // namespace