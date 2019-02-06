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

struct ScriptVersionInfo;

}

class ScriptEngine : public ScriptApi::ScriptFramework {};

struct Actor;

class MinecraftServerScriptEngine : public ScriptEngine {
public:
  /// @symbol _ZN23ScriptEngineWithContextI19ScriptServerContextE15helpDefineActorERK5ActorRN9ScriptApi18ScriptObjectHandleE
  int helpDefineActor(Actor const &, v8::Persistent<v8::Object> &);
  /// @symbol _ZN23ScriptEngineWithContextI19ScriptServerContextE12helpGetActorERKN9ScriptApi18ScriptObjectHandleEPP5Actor
  int helpGetActor(v8::Persistent<v8::Object> const &, Actor *&);
  /// @symbol _ZN23ScriptEngineWithContextI19ScriptClientContextE13isValidEntityERKN9ScriptApi17ScriptVersionInfoERKNS2_18ScriptObjectHandleERb
  int isValidEntity(ScriptApi::ScriptVersionInfo const&, v8::Persistent<v8::Object> const &, bool &);
};