#include "common.h"
#include <interface/policy.h>

#include "../custom_command.h"
#include "../patched/ScriptInterface.h"

namespace ExtAPI {
using namespace interface;
using namespace patched;

static void checkAbilityCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 1 || !info[0]->IsFunction()) {
    iso->ThrowException(Exception::TypeError(ToJS(strformat("checkAbility requires (function)"))));
    return;
  }
  Locator<Policy>()->checkAbility >> [iso, origin = Persistent<Value>{ iso, info.This() },
                                      callback = Persistent<Function>{ iso, info[0] }](Player *player, std::string const &name, bool &result) {
    HandleScope scope{ iso };
    auto &core = Locator<ScriptApi::V8CoreInterface>();
    auto ctx   = V8Context[*core].Get(iso);
    Context::Scope ctx_scope{ ctx };
    TryCatch ex{ iso };

    Local<Value> args[] = { ToJS(player), ToJS(name), ToJS(result) };

    auto ret = callback.Get(iso)->Call(origin.Get(iso), 3, args);
    if (ex.HasCaught()) {
      Log::error("Scripting", "Uncaught exception from checkAbility: %s", ex.Message()->Get() >> V8Str >> CStr);
      return;
    }
    if (ret.isNothing()) return;
    auto real_ret = ret.fromJust();
    if (real_ret->IsTrue()) result = true;
    if (real_ret->IsFalse()) result = false;
  };
}

static Register reg{ "registerComponent", "checkAbility", &checkAbilityCallback };

} // namespace ExtAPI