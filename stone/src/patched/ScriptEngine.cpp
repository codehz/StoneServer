#include "../patched.h"
#include "../server_properties.h"
#include <stone/server_hook.h>

namespace {

using namespace interface;
using namespace patched;

SHook(bool, _ZN12ScriptEngine18isScriptingEnabledEv, void *) { return Locator<ServerProperties>()->experimentMode; }

} // namespace