#pragma once

#include <hybris/dlfcn.h>
#include <memory>

#include "symbol.h"
#include "utils.h"

template <typename T> class TempPatch {
  T *address;
  T backup;

public:
  TempPatch(T *address, T value)
      : address(address)
      , backup(std::move(*address)) {
    *address = value;
  }
  ~TempPatch() { std::swap(backup, *address); }
};

template <typename Object, std::ptrdiff_t Offset, char... S> struct DirectAccess {
  static constexpr char Name[] = { S..., 0 };
  static Object &Access() {
    static Object *address = reinterpret_cast<Object *>(reinterpret_cast<char *>(hybris_dlsym(MinecraftHandle(), Name)) + Offset);
    return *address;
  }
};

template <typename Object, std::ptrdiff_t Offset, char... S> struct TempReplace {
  using DA = DirectAccess<Object, Offset, S...>;
  Object backup;
  bool owned = true;

public:
  TempReplace()
      : backup(std::move(DA::Access())) {}
  TempReplace(TempReplace const &) = delete;
  TempReplace(TempReplace &&rhs) {
    std::swap(backup, rhs.backup);
    rhs.owned = false;
  }
  TempReplace &&operator()(Object const &target) {
    DA::Access() = target;
    return std::move(*this);
  }
  TempReplace &operator=(TempReplace const &rhs) = delete;
  ~TempReplace() { if (owned) std::swap(backup, DA::Access()); }
};

template <template <typename, std::ptrdiff_t, char...> typename Target, typename Object, std::ptrdiff_t Offset> struct PartialBuilder {
  template <char... X> static Target<Object, Offset, X...> Build(Symbol<X...> sym) { return {}; }
};

#define BUILD_HELPER(Target, Object, Offset, Name) PartialBuilder<Target, Object, Offset>::Build(Name##_symbol)
