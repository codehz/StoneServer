#pragma once

#include <cstddef>

template <char... X> struct Symbol {
  static constexpr char data[]        = { X..., 0 };
  static constexpr std::size_t length = sizeof...(X);
};

template <typename T, T... X> Symbol<X...> operator""_symbol() { return {}; }