#include "../patched.h"

#include <minecraft/ServerCommandOrigin.h>

#include <interface/locator.hpp>
#include <stone/server_hook.h>

#include "../server_properties.h"

namespace {

SInstanceHook(mcpe::string, _ZNK19ServerCommandOrigin7getNameEv, ServerCommandOrigin) { return name; }

} // namespace