#pragma once

#include "log.h"
#include "utils.h"
#include <hybris/dlfcn.h>
#include <mcpelauncher/hook.h>
#include <tuple>
#include <vector>

extern std::vector<std::tuple<const char *, void *, void **>> &GetServerHookRegistry();

struct RegisterServerHook {
  static inline void InitHooks() {
    for (auto const &[sym, hook, org] : GetServerHookRegistry()) {
      Log::debug("hook", "Hook %s", sym);
      auto r = hybris_dlsym(MinecraftHandle(), sym);
      if (r == nullptr)
        Log::error("hook", "Symbol not found: %s", sym);
      else
        HookManager::hookFunction(r, hook, org);
    }
  }

  RegisterServerHook(const char *sym, void *hook, void **org) {
    GetServerHookRegistry().emplace_back(sym, hook, org);
  }

  // workaround for a warning
  template <typename S>
  RegisterServerHook(const char *sym, S hook, void **org) {
    union {
      S a;
      void *b;
    } hookUnion;
    hookUnion.a = hook;
    RegisterServerHook(sym, hookUnion.b, org);
  }
};

#define _SInstanceHook(class_inh, pclass, iname, sym, ret, args...)            \
  struct _SInstanceHook_##iname class_inh {                                    \
    static ret (_SInstanceHook_##iname::*_original)(args);                     \
    template <typename... Params>                                              \
    static ret original(pclass *_this, Params &&... params) {                  \
      return (((_SInstanceHook_##iname *)_this)->*_original)(                  \
          std::forward<Params>(params)...);                                    \
    }                                                                          \
    ret _hook(args);                                                           \
  };                                                                           \
  static RegisterServerHook _SRInstanceHook_##iname(                           \
      #sym, &_SInstanceHook_##iname::_hook,                                    \
      (void **)&_SInstanceHook_##iname::_original);                            \
  ret (_SInstanceHook_##iname::*_SInstanceHook_##iname::_original)(args);      \
  ret _SInstanceHook_##iname::_hook(args)
#define _SInstanceDefHook(iname, sym, ret, type, args...)                      \
  _SInstanceHook( : public type, type, iname, sym, ret, args)
#define _SInstanceNoDefHook(iname, sym, ret, args...)                          \
  _SInstanceHook(, void, iname, sym, ret, args)

#define _SStaticHook(pclass, iname, sym, ret, args...)                         \
  struct _SStaticHook_##iname pclass {                                         \
    static ret (*_original)(args);                                             \
    template <typename... Params> static ret original(Params &&... params) {   \
      return (*_original)(std::forward<Params>(params)...);                    \
    }                                                                          \
    static ret _hook(args);                                                    \
  };                                                                           \
  static RegisterServerHook _SRStaticHook_##iname(                             \
      #sym, &_SStaticHook_##iname::_hook,                                      \
      (void **)&_SStaticHook_##iname::_original);                              \
  ret (*_SStaticHook_##iname::_original)(args);                                \
  ret _SStaticHook_##iname::_hook(args)
#define _SStaticDefHook(iname, sym, ret, type, args...)                        \
  _SStaticHook( : public type, iname, sym, ret, args)
#define _SStaticNoDefHook(iname, sym, ret, args...)                            \
  _SStaticHook(, iname, sym, ret, args)

#define SHook2(iname, ret, sym, args...)                                       \
  _SStaticNoDefHook(iname, sym, ret, args)
#define SHook(ret, sym, args...) SHook2(sym, ret, sym, args)
#define SClasslessInstanceHook2(iname, ret, sym, args...)                      \
  _SInstanceNoDefHook(iname, sym, ret, args)
#define SClasslessInstanceHook(ret, sym, args...)                              \
  SClasslessInstanceHook2(sym, ret, sym, args)
#define SInstanceHook2(iname, ret, sym, type, args...)                         \
  _SInstanceDefHook(iname, sym, ret, type, args)
#define SInstanceHook(ret, sym, type, args...)                                 \
  SInstanceHook2(sym, ret, sym, type, args)
#define SStaticHook2(iname, ret, sym, type, args...)                           \
  _SStaticDefHook(iname, sym, ret, type, args)
#define SStaticHook(ret, sym, type, args...)                                   \
  SStaticHook2(sym, ret, sym, type, args)
