#pragma once

#include "log.h"
#include "utils.h"
#include <hybris/dlfcn.h>
#include <mcpelauncher/hook.h>

struct RegisterStaticHook {

  RegisterStaticHook(const char *sym, void *hook, void **org) {
    auto r = hybris_dlsym(MinecraftHandle(), sym);
    if (r == nullptr) { Log::error("hook", "Symbol not found: %s", sym); }
    HookManager::hookFunction(r, hook, org);
  }

  // workaround for a warning
  template <typename T> RegisterStaticHook(const char *sym, T hook, void **org) {
    union {
      T a;
      void *b;
    } hookUnion;
    hookUnion.a = hook;
    RegisterStaticHook(sym, hookUnion.b, org);
  }
};

#define _TInstanceHook(class_inh, pclass, iname, sym, ret, args...)                                                                                  \
  struct _TInstanceHook_##iname class_inh {                                                                                                          \
    static ret (_TInstanceHook_##iname::*_original)(args);                                                                                           \
    template <typename... Params> static ret original(pclass *_this, Params &&... params) {                                                          \
      return (((_TInstanceHook_##iname *)_this)->*_original)(std::forward<Params>(params)...);                                                       \
    }                                                                                                                                                \
    ret _hook(args);                                                                                                                                 \
  };                                                                                                                                                 \
  static RegisterStaticHook _TRInstanceHook_##iname(#sym, &_TInstanceHook_##iname::_hook, (void **)&_TInstanceHook_##iname::_original);              \
  ret (_TInstanceHook_##iname::*_TInstanceHook_##iname::_original)(args);                                                                            \
  ret _TInstanceHook_##iname::_hook(args)
#define _TInstanceDefHook(iname, sym, ret, type, args...) _TInstanceHook( : public type, type, iname, sym, ret, args)
#define _TInstanceNoDefHook(iname, sym, ret, args...) _TInstanceHook(, void, iname, sym, ret, args)

#define _TStaticHook(pclass, iname, sym, ret, args...)                                                                                               \
  struct _TStaticHook_##iname pclass {                                                                                                               \
    static ret (*_original)(args);                                                                                                                   \
    template <typename... Params> static ret original(Params &&... params) { return (*_original)(std::forward<Params>(params)...); }                 \
    static ret _hook(args);                                                                                                                          \
  };                                                                                                                                                 \
  static RegisterStaticHook _TRStaticHook_##iname(#sym, &_TStaticHook_##iname::_hook, (void **)&_TStaticHook_##iname::_original);                    \
  ret (*_TStaticHook_##iname::_original)(args);                                                                                                      \
  ret _TStaticHook_##iname::_hook(args)
#define _TStaticDefHook(iname, sym, ret, type, args...) _TStaticHook( : public type, iname, sym, ret, args)
#define _TStaticNoDefHook(iname, sym, ret, args...) _TStaticHook(, iname, sym, ret, args)

#define THook2(iname, ret, sym, args...) _TStaticNoDefHook(iname, sym, ret, args)
#define THook(ret, sym, args...) THook2(sym, ret, sym, args)
#define TClasslessInstanceHook2(iname, ret, sym, args...) _TInstanceNoDefHook(iname, sym, ret, args)
#define TClasslessInstanceHook(ret, sym, args...) TClasslessInstanceHook2(sym, ret, sym, args)
#define TInstanceHook2(iname, ret, sym, type, args...) _TInstanceDefHook(iname, sym, ret, type, args)
#define TInstanceHook(ret, sym, type, args...) TInstanceHook2(sym, ret, sym, type, args)
#define TStaticHook2(iname, ret, sym, type, args...) _TStaticDefHook(iname, sym, ret, type, args)
#define TStaticHook(ret, sym, type, args...) TStaticHook2(sym, ret, sym, type, args)