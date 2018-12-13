#pragma once

#include <cstddef>
#include <memory>

namespace utils {

template <typename Source, std::ptrdiff_t Offset, typename Target> struct StaticFieldAccessor {
  static Target &access(Source const &source) {
    return *reinterpret_cast<Target *>(const_cast<char *>(reinterpret_cast<char const *>(&source)) + Offset);
  }
  Target &operator[](Source const &source) const { return access(source); }
  Target &operator[](Source &source) const { return access(source); }
  friend Target &operator>>(Source &source, StaticFieldAccessor accessor) { return accessor.operator[](source); }
};

template <typename Source, typename Target, typename Method> struct Operator;
template <typename Method> struct OperatorTraits;

template <typename Source, typename Target> struct Operator<Source, Target, Target (Source::*)()> {
  Target (Source::*func)();
  Target operator()(Source const &source) const { return (source.*func)(); }
  friend Target operator>>(Source const &source, Operator accessor) { return accessor.operator()(source); }
};

template <typename Source, typename Target> struct OperatorTraits<Target (Source::*)()> {
  using type = Operator<Source, Target, Target (Source::*)()>;
};

template <typename Source, typename Target> struct Operator<Source, Target, Target (Source::*)() const> {
  Target (Source::*func)() const;
  Target operator()(Source const &source) const { return (source.*func)(); }
  friend Target operator>>(Source const &source, Operator accessor) { return accessor.operator()(source); }
};

template <typename Source, typename Target> struct OperatorTraits<Target (Source::*)() const> {
  using type = Operator<Source, Target, Target (Source::*)() const>;
};

template <typename Source, typename Target> struct Operator<Source, Target, Target (*)(Source const &)> {
  Target (*func)(Source const &);
  Target operator()(Source const &source) const { return func(source); }
  friend Target operator>>(Source const &source, Operator accessor) { return accessor.operator()(source); }
};

template <typename Source, typename Target> struct OperatorTraits<Target (*)(Source const &)> {
  using type = Operator<Source, Target, Target (*)(Source const &)>;
};

template <typename Source, typename Target> struct Operator<Source, Target, Target(Source::*)> {
  Target Source::*field;
  Target operator()(Source const &source) const { return source.*field; }
  friend Target operator>>(Source const &source, Operator accessor) { return accessor.operator()(source); }
};

template <typename Source, typename Target> struct OperatorTraits<Target(Source::*)> {
  using type = Operator<Source, Target, Target(Source::*)>;
};

template <typename Method> auto makeOperator(Method method) { return typename OperatorTraits<Method>::type{ method }; }

} // namespace utils