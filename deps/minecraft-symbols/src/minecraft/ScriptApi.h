#pragma once

#include "V8.h"
#include "json.h"
#include "std/string.h"
#include "fix.h"

struct Minecraft;

namespace ScriptApi {

struct ScriptObjectHandle {
  /// @symbol _ZTVN9ScriptApi18ScriptObjectHandleE
  static XPointer defvt;
  XPointer vtable;
  v8::Persistent<v8::Value> value;
  ScriptObjectHandle() { vtable.ptr = defvt + 2; }
  ScriptObjectHandle(v8::Persistent<v8::Value> value) {
    vtable.ptr = defvt + 2;
    this->value.Set(value.RawPointer());
  }
  operator v8::Persistent<v8::Value>() { return value; }

  ~ScriptObjectHandle() {
    ((void (*)(ScriptObjectHandle *))vtable[0])(this);
  }
};

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

struct ScriptServerContext {
  void *unk0;
  Minecraft *mc;
  void *unk8;
  void *unk12;
  void *unk16;
};

using EventInfo = mcpe::string;

class ScriptEngine : public ScriptApi::ScriptFramework {
public:
  /// @symbol _ZN12ScriptEngine17fireEventToScriptERK9EventInfoRKN9ScriptApi18ScriptObjectHandleE
  void fireEventToScript(EventInfo const &, ScriptApi::ScriptObjectHandle const &);

  /// @symbol _ZN12ScriptEngine35deserializeScriptObjectHandleToJsonERKN9ScriptApi18ScriptObjectHandleERN4Json5ValueE
  void deserializeScriptObjectHandleToJson(ScriptApi::ScriptObjectHandle const &, Json::Value &);

  /// @symbol _ZN12ScriptEngine33serializeJsonToScriptObjectHandleERN9ScriptApi18ScriptObjectHandleERKN4Json5ValueE
  void serializeJsonToScriptObjectHandle(ScriptApi::ScriptObjectHandle &, Json::Value const &);
};

struct Actor;

class MinecraftServerScriptEngine : public ScriptEngine {
public:
  /// @symbol _ZN23ScriptEngineWithContextI19ScriptServerContextE15helpDefineActorERK5ActorRN9ScriptApi18ScriptObjectHandleE
  int helpDefineActor(Actor const &, ScriptApi::ScriptObjectHandle &);
  /// @symbol _ZN23ScriptEngineWithContextI19ScriptServerContextE12helpGetActorERKN9ScriptApi18ScriptObjectHandleEPP5Actor
  int helpGetActor(ScriptApi::ScriptObjectHandle const &, Actor *&);
  /// @symbol _ZN23ScriptEngineWithContextI19ScriptClientContextE13isValidEntityERKN9ScriptApi17ScriptVersionInfoERKNS2_18ScriptObjectHandleERb
  int isValidEntity(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle const &, bool &);
};

class ScriptEventData {
public:
  ScriptEventData(mcpe::string const &);
  virtual ~ScriptEventData();

  /// @symbol _ZNK15ScriptEventData9serializeER12ScriptEngineR9EventInfoRN9ScriptApi18ScriptObjectHandleE
  bool serialize(ScriptEngine &, EventInfo &, ScriptApi::ScriptObjectHandle &) const;

private:
  virtual bool _serialize(ScriptEngine &, ScriptApi::ScriptObjectHandle &) const = 0;
};
