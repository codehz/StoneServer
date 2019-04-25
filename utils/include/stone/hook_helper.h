#pragma once

#include <hybris/dlfcn.h>

#include <ios>
#include <memory>
#include <sstream>

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

template <typename Object, std::ptrdiff_t Offset, char... S> struct GetAddress {
  static constexpr char Name[] = { S..., 0 };
  static Object *Address() {
    static Object *address = reinterpret_cast<Object *>(reinterpret_cast<char *>(GetAddress<Object, 0, S...>::Address()) + Offset);
    return address;
  }
};

template <typename Object, char... S> struct GetAddress<Object, 0, S...> {
  static constexpr char Name[] = { S..., 0 };
  static Object *Address() {
    static Object *address = reinterpret_cast<Object *>(reinterpret_cast<char *>(hybris_dlsym(MinecraftHandle(), Name)));
    return address;
  }
};

template <typename Object, std::ptrdiff_t Offset, char... S> struct DirectAccess : GetAddress<Object, Offset, S...> {
  static Object &Access() {
    static Object *address = reinterpret_cast<Object *>(reinterpret_cast<char *>(DirectAccess<Object, 0, S...>::Address()) + Offset);
    return *address;
  }
};

template <typename T> struct PrettyPrint {
  static std::string print(T t) {
    std::stringstream ss;
    ss << std::hex << t;
    return ss.str();
  }
};

template<> struct PrettyPrint<char> : PrettyPrint<int> {};

template <typename T> std::string prettyPrint(T t) { return PrettyPrint<T>::print(t); }

template <typename Object, std::ptrdiff_t Offset, char... S> struct DirectPatch {
  using DA = DirectAccess<Object, Offset, S...>;

  static void VerifiedPatch(Object const &from, Object const &to) {
    static const std::string prefix = "VerifyPatch assert failed: ";
    if (DA::Access() == from)
      DA::Access() = to;
    else
      throw std::runtime_error(prefix + DA::Name + "@" + prettyPrint(Offset) + ": " + prettyPrint(DA::Access()) + " != " + prettyPrint(from));
  }

  template<typename Fn>
  static void PatchFn(Fn fn) {
    DA::Access() = fn(DA::Access());
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
  ~TempReplace() {
    if (owned) std::swap(backup, DA::Access());
  }
};

template <template <typename, std::ptrdiff_t, char...> typename Target, typename Object, std::ptrdiff_t Offset> struct PartialBuilder {
  template <char... X> static Target<Object, Offset, X...> Build(Symbol<X...> sym) { return {}; }
};

#define BUILD_HELPER(Target, Object, Offset, Name) PartialBuilder<Target, Object, Offset>::Build(Name##_symbol)
