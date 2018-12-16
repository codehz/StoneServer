#pragma once

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

class MinecraftServerScriptEngine : public ScriptEngine {};