#include <minecraft/V8.h>
#include <stone/hook_helper.h>
#include <stone/server_hook.h>

#include "../ExtAPI/common.h"
#include "../GlobalAPI/common.h"
#include "../operators.h"
#include "../patched.h"
#include "../v8_utils.hpp"
#include "ScriptInterface.h"

#include "Flags.h"

namespace {
using namespace v8;
using namespace utils;
using namespace interface;
using namespace patched;

SHook(void, _ZN2v85Utils16ReportApiFailureEPKcS2_, char const *title, char const *content) { printf("FAILED: %s\n%s\n", title, content); }

SHook(void, _ZN9ScriptApi13LogV8CallbackERKN2v820FunctionCallbackInfoINS0_5ValueEEE, FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  std::stringstream ss;
  const auto max = info.Length();
  for (auto i = 0;; i++) {
    auto current      = info[i];
    Local<String> str = current->IsString() ? Local(String::Cast(current)) : current->ToString(iso);
    ss << V8Str(str);
    if (i < max - 1) {
      ss << ", ";
    } else {
      break;
    }
  }
  Log::info("Scripting", "log: %s", ss.str().c_str());
}

SInstanceHook(void, _ZN27MinecraftServerScriptEngineC2Ev, MinecraftServerScriptEngine) {
  original(this);
  Locator<MinecraftServerScriptEngine>() = this;
  Locator<MinecraftServerScriptEngine>() >> FieldRef(&MinecraftServerScriptEngine::core);
}

SHook(
    void *,
    _ZN9ScriptApi34CreateFunctionTemplateDataPropertyEN2v85LocalINS0_7ContextEEEPNS0_7IsolateENS1_INS0_6ObjectEEEPKcPFvRKNS0_20FunctionCallbackInfoINS0_5ValueEEEENS1_ISB_EE,
    void *a, void *b, void *c, char const *name, void (*callback)(v8::FunctionCallbackInfo<v8::Value> const &), void *external) {
  auto &registry = ExtAPI::Register::registry;
  auto it        = registry.find(name);
  if (it != registry.end())
    for (auto [name, func] : it->second) original(a, b, c, name, func, external);
  return original(a, b, c, name, callback, external);
}

SInstanceHook(int, _ZN9ScriptApi15V8CoreInterface10initializeERNS_12ScriptReportE, ScriptApi::V8CoreInterface, void *report) {
  auto ret = original(this, report);
  auto iso = V8Isolate[*this];
  HandleScope scope{ iso };
  auto ctx = V8Context[*this].Get(iso);
  Context::Scope ctx_scope{ ctx };
  auto global       = ctx->Global();
  auto s_globalThis = toJS<std::string>(iso, "globalThis");
  if (!global->Has(s_globalThis)) { global->Set(s_globalThis, global); }
  for (auto fn : WebAPI::Register::registry) fn(global, iso, ctx);
  return ret;
}

} // namespace