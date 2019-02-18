#pragma once

#include "V8.h"
#include "std/string.h"

struct Minecraft;

namespace ScriptApi {

using ScriptObjectHandle = v8::Persistent<v8::Value>;

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
