#pragma once

#include <cassert>
#include <cstdint>
#include <functional>
#include <pthread.h>

#include <interface/locator.hpp>
#include <minecraft/Block.h>
#include <minecraft/Command.h>
#include <minecraft/CommandMessage.h>
#include <minecraft/CommandOutput.h>
#include <minecraft/CommandRegistry.h>
#include <minecraft/CommandSelector.h>
#include <minecraft/ScriptApi.h>
#include <minecraft/V8.h>
#include <stone/magic_func.h>
#include <stone/server_hook.h>

#include "operators.h"
#include "patched/ScriptInterface.h"
#include "v8_utils.hpp"

struct ParameterDef {
  size_t size;
  std::string name;
  typeid_t<CommandRegistry> type;
  Parser parser;
  void (*init)(void *);
  void (*deinit)(void *);
  v8::Local<v8::Value> (*fetch)(void *, CommandOrigin &, v8::Isolate *iso);
  std::string softEnum;
  bool optional;

  void makeOptional() { optional = true; }
};

struct MyCommandVTable {
  v8::Isolate *iso;
  std::vector<ParameterDef> defs;
  std::function<v8::MaybeLocal<v8::Value>(v8::Isolate *, int, v8::Local<v8::Value> *)> exec;
};
static inline ParameterDef messageParameter(std::string const &name) {
  return {
    .size   = sizeof(CommandMessage),
    .name   = name,
    .type   = *CommandMessage::tid,
    .parser = CommandMessage::parser,
    .init   = CommandMessage::constructor,
    .deinit = CommandMessage::destructor,
    .fetch  = [](void *self, CommandOrigin &orig, v8::Isolate *iso) -> v8::Local<v8::Value> {
      return v8::String::NewFromUtf8(iso, ((CommandMessage *)self)->getMessage(orig).c_str());
    },
  };
}

template <typename T> struct FetchGenerator;

template <typename T> static inline void geninit(void *ptr) { new (ptr) T(); }
template <typename T> static inline void gendeinit(void *ptr) { ((T *)ptr)->~T(); }
template <typename T> static inline v8::Local<v8::Value> genfetch(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return FetchGenerator<T>::generate(self, orig, iso);
}

template <> inline v8::Local<v8::Value> genfetch<mcpe::string>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return v8::String::NewFromUtf8(iso, ((mcpe::string *)self)->c_str());
}
template <> inline v8::Local<v8::Value> genfetch<int>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return v8::Integer::New(iso, *(int *)self);
}
template <> inline v8::Local<v8::Value> genfetch<float>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return v8::Number::New(iso, *(float *)self);
}
template <> inline v8::Local<v8::Value> genfetch<bool>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return v8::Boolean::New(iso, *(bool *)self);
}
template <> inline v8::Local<v8::Value> genfetch<CommandRawText>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return v8::String::NewFromUtf8(iso, ((mcpe::string *)self)->c_str());
}
template <> inline v8::Local<v8::Value> genfetch<Block *>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return v8::toJS<CompoundTag const &>(iso, (*(Block **)self)->tag2);
}
template <> inline v8::Local<v8::Value> genfetch<CommandPosition>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  auto strX      = v8::String::NewFromUtf8(iso, "x");
  auto strY      = v8::String::NewFromUtf8(iso, "y");
  auto strZ      = v8::String::NewFromUtf8(iso, "z");
  auto ret       = v8::Object::New(iso);
  auto [x, y, z] = ((CommandPosition *)self)->getPosition(orig);
  ret->Set(strX, v8::Number::New(iso, x));
  ret->Set(strY, v8::Number::New(iso, y));
  ret->Set(strZ, v8::Number::New(iso, z));
  return ret;
}

template <typename T> struct FetchGenerator<CommandSelector<T>> {
  static inline v8::Local<v8::Value> generate(void *self, CommandOrigin &orig, v8::Isolate *iso) {
    using namespace interface;
    auto results = ((CommandSelector<T> *)self)->newResults(orig);
    auto ret     = v8::Array::New(iso, results->size());
    auto &engine = Locator<MinecraftServerScriptEngine>();
    int index    = 0;
    for (auto actor : *results) {
      v8::Persistent<v8::Value> pers;
      engine->helpDefineActor(*actor, pers);
      ret->Set(index++, pers.Get(iso));
    }
    return ret;
  }
};

template <typename T> static inline ParameterDef commonParameter(std::string const &name) {
  return {
    .size   = sizeof(T),
    .name   = name,
    .type   = *CommonType<T>::tid,
    .parser = CommonType<T>::parser,
    .init   = &geninit<T>,
    .deinit = &gendeinit<T>,
    .fetch  = &genfetch<T>,
  };
};

static inline ParameterDef enumParameter(std::string const &name, std::string const &type) {
  auto ret     = commonParameter<mcpe::string>(name);
  ret.softEnum = type;
  return ret;
}

CommandOrigin *current_orig = nullptr;

struct CustomCommand : Command {
  MyCommandVTable *vt;
  CustomCommand(MyCommandVTable *vt)
      : Command()
      , vt(vt) {
    size_t offset = 0;
    for (auto &def : vt->defs) {
      if (def.init) def.init((void *)((size_t)this + sizeof(CustomCommand) + offset));
      offset += def.size;
    }
  }

  ~CustomCommand() {
    size_t offset = 0;
    for (auto def : vt->defs) {
      if (def.deinit) def.deinit((void *)((size_t)this + sizeof(CustomCommand) + offset));
      offset += def.size;
    }
  }

  void execute(CommandOrigin &orig, CommandOutput &outp) {
    using namespace utils;
    using namespace interface;
    using namespace v8;
    using namespace patched;
    auto size     = vt->defs.size();
    size_t offset = 0;
    auto &iso     = vt->iso;
    assert(size < 32);
    Local<Value> params[size];

    HandleScope scope{ iso };
    auto &core = Locator<ScriptApi::V8CoreInterface>();
    auto ctx   = V8Context[*core].Get(iso);
    Context::Scope ctx_scope{ ctx };
    TryCatch ex{ iso };

    for (size_t i = 0; i < size; i++) {
      auto &def = vt->defs[i];
      params[i] = def.fetch((void *)((size_t)this + sizeof(CustomCommand) + offset), orig, iso);
      offset += def.size;
    }
    current_orig = &orig;
    auto result  = vt->exec(iso, size, params);
    current_orig = nullptr;
    if (ex.HasCaught()) {
      outp.error(ex.Message()->Get() >> V8Str >> CStr, {});
      return;
    }
    if (!result.isNothing() || !result.fromJust()->IsNullOrUndefined()) {
      auto str = result.fromJust()->ToString(iso) >> V8Str;
      if (str.size() != 0) return outp.success(str, {});
    }
    outp.success();
  }

  static auto create(MyCommandVTable *vt) {
    size_t size = 0;
    for (auto def : vt->defs) size += def.size;
    auto ptr = new (malloc(sizeof(CustomCommand) + size)) CustomCommand(vt);
    return std::unique_ptr<Command>(ptr);
  }
};

SHook(void, _ZN9XPCommand5setupER15CommandRegistry, CommandRegistry &reg) {
  original(reg);
  interface::Locator<CommandRegistry>() = &reg;
}

auto registerCustomCommand(std::string name, std::string desc, int lvl) {
  using namespace interface;
  Locator<CommandRegistry>()->registerCommand(name, desc.c_str(), lvl, 0, 0);
  return [=](MyCommandVTable &rvt) {
    Locator<CommandRegistry>()->registerCustomOverload(
        name, { 0, INT32_MAX }, gen_function(new MyCommandVTable(rvt), CustomCommand::create), [&](CommandRegistry::Overload &overload) {
          size_t offset = sizeof(CustomCommand);
          for (auto &p : rvt.defs) {
            if (p.softEnum.length()) {
              overload.params.emplace_back(CommandParameterData(p.type, p.parser, p.name.c_str(), 2, p.softEnum.c_str(), offset, p.optional, -1));
            } else {
              overload.params.emplace_back(CommandParameterData(p.type, p.parser, p.name.c_str(), 0, nullptr, offset, p.optional, -1));
            }
            offset += p.size;
          }
        });
  };
}

void registerCustomEnum(mcpe::string name, std::vector<mcpe::string> list) {
  using namespace interface;
  Locator<CommandRegistry>()->addSoftEnum(name, list, true);
}