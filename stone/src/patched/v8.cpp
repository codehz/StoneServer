#include <interface/chat.h>
#include <interface/tick.h>
#include <minecraft/V8.h>
#include <stone-api/Script.h>
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
    Local<String> str = current->IsString() ? Local<String>(current) : current->ToString(iso);
    ss << V8Str(str);
    if (i < max - 1) {
      ss << ", ";
    } else {
      break;
    }
  }
  Log::info("Scripting", "log: %s", ss.str().c_str());
}

SInstanceHook(void, _ZN27MinecraftServerScriptEngineC1ER14ServerInstance, MinecraftServerScriptEngine, ServerInstance &instance) {
  original(this, instance);
  Locator<MinecraftServerScriptEngine>() = this;
  Locator<ScriptApi::V8CoreInterface>()  = this->core;
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

SStaticHook(Local<Value>, _ZN2v87Context3NewEPNS_7IsolateEPNS_22ExtensionConfigurationENS_10MaybeLocalINS_14ObjectTemplateEEENS5_INS_5ValueEEE,
            Context, v8::Isolate *iso, v8::ExtensionConfiguration *config, v8::Local<v8::ObjectTemplate> temp, v8::MaybeLocal<v8::Value> global) {
  auto new_temp = ObjectTemplate::New(iso, v8::Local<v8::FunctionTemplate>());
  new_temp->SetAccessorProperty(ToJS("globalThis"), v8::FunctionTemplate::New(iso, +[](v8::FunctionCallbackInfo<v8::Value> const &info) {
                                  info.GetReturnValue().Set(info.This());
                                }));
  for (auto fn : GlobalAPI::Register::registry) fn(new_temp, iso);
  for (auto fn : ExtAPI::Register::injecteds) fn(iso);
  Locator<Tick>()->tick >> std::bind(&Isolate::RunMicrotasks, iso);
  return original(iso, config, new_temp, global);
}

static patched::details::RegisterPatchInit pinit([] {
  using namespace api;
  Locator<ScriptService<ServerSide>>()->emit >> [](EventData const &data) {
    if (!Locator<ScriptApi::V8CoreInterface>()) return;
    auto &core = *Locator<ScriptApi::V8CoreInterface>();
    auto &iso  = V8Isolate[core];
    HandleScope scope{ iso };
    Isolate::Scope iso_scope{ iso };
    auto ctx = V8Context[core].Get(iso);
    Context::Scope ctx_scope{ ctx };
    Locator<MinecraftServerScriptEngine>()->fireEventToScript("script:" + data.name, Persistent<Value>{ iso, ToJS(data.data) });
  };
  Locator<Chat>() >> [](auto &chat) {
    chat.onPlayerChat >> [](Player &player, std::string const text) {
      if (!Locator<ScriptApi::V8CoreInterface>()) return;
      auto &core = *Locator<ScriptApi::V8CoreInterface>();
      auto &iso  = V8Isolate[core];
      HandleScope scope{ iso };
      Isolate::Scope iso_scope{ iso };
      auto ctx = V8Context[core].Get(iso);
      Context::Scope ctx_scope{ ctx };
      auto obj = Object::New(iso);
      obj->Set(ToJS("sender"), ToJS((Actor *)&player));
      obj->Set(ToJS("content"), ToJS(text));
      Locator<MinecraftServerScriptEngine>()->fireEventToScript("stoneserver:chat_received", Persistent<Value>{ iso, obj });
    };
  };
});

} // namespace