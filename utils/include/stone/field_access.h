#pragma once

#include <cstddef>

namespace utils {

template <typename Source, std::ptrdiff_t Offset, typename Target> Target &accessField(Source const &source) {
  return *reinterpret_cast<Target *>(const_cast<char *>(reinterpret_cast<char const *>(&source)) + Offset);
};

template <typename Source, std::ptrdiff_t Offset, typename Target> struct FieldAccessor {
  static Target &access(Source const &source) { return accessField<Source, Offset, Target>(source); }
  Target &operator[](Source const &source) const { return accessField<Source, Offset, Target>(source); }
};

} // namespace utils