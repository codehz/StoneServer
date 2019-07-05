#include "../patched.h"
#include "../server_properties.h"
#include "../dumper.h"
#include <stone/server_hook.h>

extern bool GlobalExperimentMode;

namespace {

using namespace interface;
using namespace patched;

SHook(bool, _ZN12ScriptEngine18isScriptingEnabledEv, void *) { return Locator<ServerProperties>()->experimentMode; }

SHook(void, _ZN2v88internal7Isolate6DeinitEv, void *self) {}

} // namespace