#include "../patched.h"

#include <interface/locator.hpp>
#include <stone/server_hook.h>

#include "../server_properties.h"

namespace {

inline static bool eduMode() { return true; };
SHook(bool, _ZN16EducationOptions24isBaseCodeBuilderEnabledEv) { return eduMode(); }
SHook(bool, _ZN16EducationOptions18isChemistryEnabledEv) { return eduMode(); }
SHook(bool, _ZN16EducationOptions20isCodeBuilderEnabledEv) { return eduMode(); }
SHook(bool, _ZN16EducationOptions18isEducationEnabledEv) { return eduMode(); }

} // namespace