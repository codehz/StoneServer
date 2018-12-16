#include "../patched.h"

#include <stone/server_hook.h>

#include <interface/locator.hpp>

namespace {

SClasslessInstanceHook(void, _ZN22ScriptEventCoordinator24sendScriptBroadcastEventERKSs16RegistrationTypeb, mcpe::string const &event, int type,
                       bool flag) {
  Log::debug("Scripting", "event: %s %d %d", event.c_str(), type, flag);
  original(this, event, type, flag);
}

SClasslessInstanceHook(void, _ZN22ScriptEventCoordinator22sendScriptGetComponentERKSs16RegistrationTypeb, mcpe::string const &component, int type,
                       bool flag) {
  Log::debug("Scripting", "component: %s %d %d", component.c_str(), type, flag);
  original(this, component, type, flag);
}

SClasslessInstanceHook(void, _ZN22ScriptEventCoordinator15sendScriptErrorERKSsS1_, mcpe::string const &source, mcpe::string const &content) {
  Log::error("Scripting", "%s: %s", source.c_str(), content.c_str());
  original(this, source, content);
}

SClasslessInstanceHook(void, _ZN22ScriptEventCoordinator23sendScriptInternalErrorERKSs, mcpe::string const &content) {
  Log::error("Scripting", "internal error: %s", content.c_str());
  original(this, content);
}

SClasslessInstanceHook(void, _ZN22ScriptEventCoordinator24sendScriptListenForEventERKSs, mcpe::string const &event) {
  Log::debug("Scripting", "listen: %s", event.c_str());
  original(this, event);
}

SClasslessInstanceHook(void, _ZN22ScriptEventCoordinator16sendScriptLoadedERKSsy, mcpe::string const &name, unsigned long long unk) {
  Log::debug("Scripting", "loaded: %s %llu", name.c_str(), unk);
  original(this, name, unk);
}

SClasslessInstanceHook(void, _ZN22ScriptEventCoordinator13sendScriptRanERKSsS1_b, mcpe::string const &source, mcpe::string const &content) {
  Log::info("Scripting", "running %s", source.c_str());
  original(this, source, content);
}

} // namespace