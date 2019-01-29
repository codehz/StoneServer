#pragma once

#include "V8.h"
#include "std/string.h"

namespace ScriptApi {

using ScriptObjectHandle = void *;

class ScriptReport {
  char filler[0xC];
};

class V8CoreInterface {
  char filler[0x80];
};

struct ScriptFramework {
  void **vtable;
  V8CoreInterface *core; // 8
  char pad8[0x24 - 0x8];
  ScriptReport *report;
};

}

class ScriptEngine : public ScriptApi::ScriptFramework {};

struct Actor;

class MinecraftServerScriptEngine : public ScriptEngine {
  /// @symbol _ZN23ScriptEngineWithContextI19ScriptServerContextE16helpDefineEntityERK5ActorRN9ScriptApi18ScriptObjectHandleE
public:
  int helpDefineEntity(Actor const &, v8::Persistent<v8::Object> &);
};