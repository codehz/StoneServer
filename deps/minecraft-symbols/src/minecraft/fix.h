#pragma once

#include <cstdint>

struct XPointer {
  void *ptr;

  template <typename T> constexpr operator T() const {
    union CVT {
      T target;
      void *source;
      CVT(void *source)
          : source(source) {}
    } cvt{ ptr };
    return cvt.target;
  }

  template <typename T> constexpr bool operator==(T const &rhs) {
    union {
      T source;
      void *target;
    } cvt;
    cvt.source = rhs;
    return cvt.target == ptr;
  }

  constexpr bool operator==(std::nullptr_t nptr) { return ptr == nullptr; }

  constexpr bool operator==(void *rhs) { return ptr == rhs; }

  constexpr void **operator+(std::intptr_t off) { return ((void **)*this) + off; }

  constexpr void *&operator[](std::intptr_t off) { return ((void **)*this)[off]; }
};