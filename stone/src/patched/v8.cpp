#include <minecraft/DedicatedServerCommandOrigin.h>
#include <minecraft/MinecraftCommands.h>
#include <minecraft/V8.h>
#include <stone/server_hook.h>
#include <wchar.h>

#include "../custom_command.hpp"
#include "../operators.h"
#include "../patched.h"

namespace {
using namespace v8;
using namespace utils;
using namespace interface;

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

SHook(void *, _ZN2v82V818GlobalizeReferenceEPNS_8internal7IsolateEPPNS1_6ObjectE, Isolate *iso, void *obj) {
  static bool first = true;
  if (first) {
    first = false;

    Locator<Isolate>() = iso;
    auto ret           = original(iso, obj);
    Locator<Persistent<Context>, identity>().Set(ret);
    return ret;
  }
  return original(iso, obj);
}

void registerCommandCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  if (info.Length() != 4) {
    Log::error("Scripting", "registerCommand requires 4 arguments(current: %d)", info.Length());
    return;
  }
  if (!info[0]->IsString() || !info[1]->IsString() || !info[2]->IsNumber() || !info[3]->IsArray()) {
    Log::error("Scripting", "registerCommand requires (string, string, number, array)");
    return;
  }
  const auto command = String::Cast(info[0]);
  const auto desc    = String::Cast(info[1]);
  const auto lvl     = Integer::Cast(info[2]);
  auto strArguments  = String::NewFromUtf8(iso, "arguments");
  auto strHandler    = String::NewFromUtf8(iso, "handler");
  auto strName       = String::NewFromUtf8(iso, "name");
  auto strType       = String::NewFromUtf8(iso, "type");
  auto strOptional   = String::NewFromUtf8(iso, "optional");
  auto definitions   = Array::Cast(info[3]);

  auto registerOverload = registerCustomCommand(command >> V8Str >> StdStr, desc >> V8Str >> StdStr, (int)lvl->Value());
  for (unsigned i = 0; i < definitions->Length(); i++) {
    const auto val = definitions->Get(i);
    if (!val->IsObject()) {
      Log::error("Scripting", "registerCommand definition requires object");
      return;
    }
    auto obj = Object::Cast(val);
    if (!obj->Has((Value *)strArguments) || !obj->Has((Value *)strHandler)) {
      Log::error("Scripting", "registerCommand definition requires { arguments: array, handler: function, optional?: boolean }");
      return;
    }
    auto srcArguments = obj->Get((Value *)strArguments);
    if (!srcArguments->IsArray()) {
      Log::error("Scripting", "registerCommand definition arguments requires array");
      return;
    }
    auto arguments  = Array::Cast(srcArguments);
    auto srcHandler = obj->Get((Value *)strHandler);
    if (!srcHandler->IsFunction()) {
      Log::error("Scripting", "registerCommand definition handler requires function");
      return;
    }
    MyCommandVTable mvt;
    auto argc = arguments->Length();
    for (unsigned i = 0; i < argc; i++) {
      auto srcArg = arguments->Get(i);
      if (!srcArg->IsObject()) {
        Log::error("Scripting", "registerCommand definition arguments requires object");
        return;
      }
      auto arg = Object::Cast(srcArg);
      if (!arg->Has((Value *)strName) || !arg->Has((Value *)strType)) {
        Log::error("Scripting", "registerCommand definition arguments requires { name: string, type: string }");
        return;
      }
      auto argName = arg->Get((Value *)strName);
      if (!argName->IsString()) {
        Log::error("Scripting", "registerCommand definition arguments name requires string");
        return;
      }
      auto argType = arg->Get((Value *)strType);
      if (!argType->IsString()) {
        Log::error("Scripting", "registerCommand definition arguments type requires string");
        return;
      }
      auto theName = String::Cast(argName) >> V8Str;
      auto theType = String::Cast(argType) >> V8Str;
      if (theType == "message") {
        mvt.defs.push_back(messageParameter(theName));
      } else if (theType == "string") {
        mvt.defs.push_back(commonParameter<mcpe::string>(theName));
      } else if (theType == "int") {
        mvt.defs.push_back(commonParameter<int>(theName));
      } else if (theType == "float") {
        mvt.defs.push_back(commonParameter<float>(theName));
      } else if (theType == "bool") {
        mvt.defs.push_back(commonParameter<bool>(theName));
      } else if (theType == "text") {
        mvt.defs.push_back(commonParameter<CommandRawText>(theName));
      } else if (theType == "position") {
        mvt.defs.push_back(commonParameter<CommandPosition>(theName));
      } else {
        Log::error("Scripting", "registerCommand definition arguments type is unknown");
        return;
      }
      auto optional = arg->Get((Value *)strOptional)->BooleanValue();
      if (optional) mvt.defs.rbegin()->makeOptional();
    }
    mvt.exec = [self = Persistent<Value>(iso, info.This()), handler = Persistent<Function>(iso, Function::Cast(srcHandler))](
                   Isolate *iso, int argc, v8::Local<v8::Value> *argv) -> v8::Local<v8::Value> {
      auto origin = self.Get(iso);
      auto func   = handler.Get(iso);
      return func->Call(origin, argc, argv);
    };
    registerOverload(mvt);
  }
}

void invokeCommandCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  if (info.Length() != 1) {
    Log::error("Scripting", "invokeCommand requires 1 arguments(current: %d)", info.Length());
    return;
  }
  if (!info[0]->IsString()) {
    Log::error("Scripting", "invokeCommand requires (string)");
    return;
  }
  if (!current_orig) {
    Log::error("Scripting", "invokeCommand need be invoked inside custom command execution context");
    return;
  }
  auto command = Local(String::Cast(info[0])) >> V8Str;
  auto result  = patched::withCommandOutput([&] {
    auto commandOrigin = current_orig->clone();
    Locator<MinecraftCommands>()->requestCommandExecution(std::move(commandOrigin), command, 4, true);
  });
  info.GetReturnValue().Set(String::NewFromUtf8(iso, result.c_str()));
}

void invokeConsoleCommandCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  if (info.Length() != 1) {
    Log::error("Scripting", "invokeConsoleCommand requires 2 arguments(current: %d)", info.Length());
    return;
  }
  if (!info[0]->IsString() || !info[1]->IsString()) {
    Log::error("Scripting", "invokeConsoleCommand requires (string, string)");
    return;
  }
  auto orig    = Local(String::Cast(info[0])) >> V8Str;
  auto command = Local(String::Cast(info[1])) >> V8Str;
  auto result  = patched::withCommandOutput([&] {
    auto commandOrigin = std::make_unique<DedicatedServerCommandOrigin>(orig, *Locator<Minecraft>());
    Locator<MinecraftCommands>()->requestCommandExecution(std::move(commandOrigin), command, 4, true);
  });
  info.GetReturnValue().Set(String::NewFromUtf8(iso, result.c_str()));
}

SHook(
    void *,
    _ZN9ScriptApi34CreateFunctionTemplateDataPropertyEN2v85LocalINS0_7ContextEEEPNS0_7IsolateENS1_INS0_6ObjectEEEPKcPFvRKNS0_20FunctionCallbackInfoINS0_5ValueEEEENS1_ISB_EE,
    void *a, void *b, void *c, char const *name, void (*callback)(v8::FunctionCallbackInfo<v8::Value> const &), void *external) {
  if (strcmp(name, "registerComponent") == 0) {
    original(a, b, c, "registerCommand", registerCommandCallback, external);
    original(a, b, c, "invokeCommand", invokeCommandCallback, external);
    original(a, b, c, "invokeConsoleCommand", invokeConsoleCommandCallback, external);
  }
  return original(a, b, c, name, callback, external);
}

} // namespace