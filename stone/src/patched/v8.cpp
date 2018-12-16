#include <minecraft/V8.h>
#include <stone/server_hook.h>
#include <wchar.h>

#include "../operators.h"
#include "../patched.h"

namespace {
using namespace v8;
using namespace utils;
using namespace interface;

SHook(void, _ZN9ScriptApi13LogV8CallbackERKN2v820FunctionCallbackInfoINS0_5ValueEEE, FunctionCallbackInfo<Value> const &info) {
  if (info.Length() != 1 || !info[0]->IsString()) {
    Log::info("Scripting", "Failed to print log");
    return;
  }
  Local<String> str   = String::Cast(info[0]);
  std::string content = str >> V8Str;
  Log::info("Scripting", "log: %s", content.c_str());
}

SInstanceHook(void, _ZN27MinecraftServerScriptEngineC2Ev, MinecraftServerScriptEngine) {
  original(this);
  Locator<MinecraftServerScriptEngine>() = this;
  Locator<MinecraftServerScriptEngine>() >> FieldRef(&MinecraftServerScriptEngine::core);
}

} // namespace