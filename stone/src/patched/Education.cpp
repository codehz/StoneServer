#include "../patched.h"

#include <interface/locator.hpp>
#include <stone/server_hook.h>

#include "../server_properties.h"

namespace {

SHook(bool, _ZN16EducationOptions24isBaseCodeBuilderEnabledEv) { return true; }
SHook(bool, _ZN16EducationOptions18isChemistryEnabledEv) { return true; }
SHook(bool, _ZN16EducationOptions20isCodeBuilderEnabledEv) { return true; }

} // namespace