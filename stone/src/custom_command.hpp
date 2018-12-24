#pragma once

#include <cassert>
#include <cstdint>
#include <functional>
#include <pthread.h>

#include <interface/locator.hpp>
#include <minecraft/Command.h>
#include <minecraft/CommandMessage.h>
#include <minecraft/CommandOutput.h>
#include <minecraft/CommandRegistry.h>
#include <minecraft/V8.h>
#include <stone/magic_func.h>
#include <stone/server_hook.h>

#include "operators.h"

struct ParameterDef {
  size_t size;
  std::string name;
  typeid_t<CommandRegistry> type;
  Parser parser;
  void (*init)(void *);
  void (*deinit)(void *);
  v8::Local<v8::Value> (*fetch)(void *, CommandOrigin &, v8::Isolate *iso);
  std::string softEnum;
  std::vector<std::string> enumItems;
  bool optional;
};

struct MyCommandVTable {
  std::vector<ParameterDef> defs;
  std::function<v8::Local<v8::Value>(v8::Isolate *, int, v8::Local<v8::Value> *)> exec;
};

static ParameterDef messageParameter(std::string const &name) {
  return {
    .size   = sizeof(CommandMessage),
    .name   = name,
    .type   = *CommandMessage::tid,
    .parser = CommandMessage::parser,
    .init   = CommandMessage::constructor,
    .deinit = CommandMessage::destructor,
    .fetch  = [](void *self, CommandOrigin &orig,
                v8::Isolate *iso) { return (v8::Local<v8::Value>)v8::String::NewFromUtf8(iso, ((CommandMessage *)self)->getMessage(orig).c_str()); },
  };
}

template <typename T> static void geninit(void *ptr) { new (ptr) T(); }
template <typename T> static void gendeinit(void *ptr) { ((T *)ptr)->~T(); }
template <typename T> static v8::Local<v8::Value> genfetch(void *self, CommandOrigin &orig, v8::Isolate *iso) { return {}; }

template <> v8::Local<v8::Value> genfetch<mcpe::string>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return (v8::Local<v8::Value>)v8::String::NewFromUtf8(iso, ((mcpe::string *)self)->c_str());
}
template <> v8::Local<v8::Value> genfetch<int>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return (v8::Local<v8::Value>)v8::Integer::New(iso, *(int *)self);
}
template <> v8::Local<v8::Value> genfetch<float>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return (v8::Local<v8::Value>)v8::Number::New(iso, *(float *)self);
}
template <> v8::Local<v8::Value> genfetch<bool>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return (v8::Local<v8::Value>)v8::Boolean::New(iso, *(bool *)self);
}
template <> v8::Local<v8::Value> genfetch<CommandRawText>(void *self, CommandOrigin &orig, v8::Isolate *iso) {
  return (v8::Local<v8::Value>)v8::String::NewFromUtf8(iso, ((mcpe::string *)self)->c_str());
}

template <typename T> static ParameterDef commonParameter(std::string const &name) {
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

static v8::Local<v8::Context> *hack_ctx;

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
    auto size     = vt->defs.size();
    size_t offset = 0;
    auto &iso     = Locator<Isolate>();
    assert(size < 32);
    Local<Value> params[size];

    HandleScope scope{ iso };
    auto ctx = Context::New(iso, nullptr, nullptr, nullptr);
    Context::Scope ctx_scope{ ctx };
    hack_ctx = &ctx;

    for (size_t i = 0; i < size; i++) {
      auto &def = vt->defs[i];
      params[i] = def.fetch((void *)((size_t)this + sizeof(CustomCommand) + offset), orig, iso);
      offset += def.size;
    }
    auto result = vt->exec(iso, size, params);
    if (!result->IsNullOrUndefined()) {
      auto str = result->ToString(iso) >> V8Str;
      outp.addMessage(str, {}, 0);
    }
    outp.success();
    hack_ctx = nullptr;
  }

  static auto create(MyCommandVTable *vt) {
    size_t size = 0;
    for (auto def : vt->defs) size += def.size;
    auto ptr = new (malloc(sizeof(CustomCommand) + size)) CustomCommand(vt);
    return std::unique_ptr<Command>(ptr);
  }
};

SHook(v8::Local<v8::Context>, _ZN2v87Isolate17GetCurrentContextEv, void *self) {
  if (hack_ctx) return *hack_ctx;
  return original(self);
}

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
          for (auto p : rvt.defs) {
            overload.params.emplace_back(CommandParameterData(p.type, p.parser, p.name.c_str(), 0, nullptr, offset, p.optional, -1));
            offset += p.size;
          }
        });
  };
}