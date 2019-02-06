#include "../patched.h"
#include <stone/server_hook.h>

namespace {

SHook(bool, _ZN12ScriptEngine18isScriptingEnabledEv, void*) {
  return true;
}

}