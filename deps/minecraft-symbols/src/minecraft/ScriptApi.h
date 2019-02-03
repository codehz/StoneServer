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
public:
  /// @symbol _ZN23ScriptEngineWithContextI19ScriptServerContextE16helpDefineEntityERK5ActorRN9ScriptApi18ScriptObjectHandleE
  int helpDefineEntity(Actor const &, v8::Persistent<v8::Object> &);
  /// @symbol _ZN23ScriptEngineWithContextI19ScriptServerContextE12helpGetActorERKN9ScriptApi18ScriptObjectHandleEPP5Actor
  int helpGetActor(v8::Persistent<v8::Object> const &, Actor *&);
  /// @symbol _ZN23ScriptEngineWithContextI19ScriptServerContextE13isValidEntityERKN9ScriptApi18ScriptObjectHandleERb
  int isValidEntity(v8::Persistent<v8::Object> const &, bool &);
};