#pragma once

#include <cstddef>
#include <memory>

namespace utils {

template <typename Source, std::ptrdiff_t Offset, typename Target> struct FieldAccessor {
  static Target &access(Source const &source) {
    return *reinterpret_cast<Target *>(const_cast<char *>(reinterpret_cast<char const *>(&source)) + Offset);
  }
  Target &operator[](Source const &source) const { return access(source); }
  Target &operator[](Source &source) const { return access(source); }
};

template <typename Source, typename Target> struct FieldIndirectAccessor {
  Target (*func)(Source const &);
  Target operator()(Source const &source) const { return func(source); }
};

template <typename Source, typename Target> FieldIndirectAccessor<Source, Target> makeFieldIndirectAccessor(Target (*func)(Source const &)) {
  return { func };
}

} // namespace utils