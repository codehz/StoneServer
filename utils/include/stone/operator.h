#pragma once

#include <cstddef>
#include <functional>
#include <memory>

namespace utils {

template <typename Source, std::ptrdiff_t Offset, typename Target> struct StaticFieldAccessor {
  static Target &access(Source const &source) {
    return *reinterpret_cast<Target *>(const_cast<char *>(reinterpret_cast<char const *>(&source)) + Offset);
  }
  inline Target &operator[](Source const &source) const { return access(source); }
  inline Target &operator[](Source &source) const { return access(source); }
  inline Target &operator()(Source const &source) const { return access(source); }
  inline Target &operator()(Source &source) const { return access(source); }
  inline friend Target &operator>>(Source &source, StaticFieldAccessor accessor) { return access(source); }
};

template <typename Source, typename Target, typename Method> struct Operator;
template <typename Method> struct OperatorTraits;

template <typename Source, typename Target> struct Operator<Source, Target, Target (Source::*)()> {
  Target (Source::*func)();
  inline Target operator()(Source const &source) const { return (source.*func)(); }
  inline friend Target operator>>(Source const &source, Operator accessor) { return accessor.operator()(source); }
};

template <typename Source, typename Target> struct OperatorTraits<Target (Source::*)()> {
  using type = Operator<Source, Target, Target (Source::*)()>;
};

template <typename Source, typename Target> struct Operator<Source, Target, Target (Source::*)() const> {
  Target (Source::*func)() const;
  inline Target operator()(Source const &source) const { return (source.*func)(); }
  inline friend Target operator>>(Source const &source, Operator accessor) { return accessor.operator()(source); }
};

template <typename Source, typename Target> struct OperatorTraits<Target (Source::*)() const> {
  using type = Operator<Source, Target, Target (Source::*)() const>;
};

template <typename Source, typename Target> struct Operator<Source, Target, Target (Source::*)() noexcept> {
  Target (Source::*func)() noexcept;
  inline Target operator()(Source const &source) const { return (source.*func)(); }
  inline friend Target operator>>(Source const &source, Operator accessor) { return accessor.operator()(source); }
};

template <typename Source, typename Target> struct OperatorTraits<Target (Source::*)() noexcept> {
  using type = Operator<Source, Target, Target (Source::*)() noexcept>;
};

template <typename Source, typename Target> struct Operator<Source, Target, Target (Source::*)() const noexcept> {
  Target (Source::*func)() const noexcept;
  inline Target operator()(Source const &source) const { return (source.*func)(); }
  inline friend Target operator>>(Source const &source, Operator accessor) { return accessor.operator()(source); }
};

template <typename Source, typename Target> struct OperatorTraits<Target (Source::*)() const noexcept> {
  using type = Operator<Source, Target, Target (Source::*)() const noexcept>;
};

template <typename Source, typename Target> struct Operator<Source, Target, Target (*)(Source const &)> {
  Target (*func)(Source const &);
  inline Target operator()(Source const &source) const { return func(source); }
  inline friend Target operator>>(Source const &source, Operator accessor) { return accessor.operator()(source); }
};

template <typename Source, typename Target> struct OperatorTraits<Target (*)(Source const &)> {
  using type = Operator<Source, Target, Target (*)(Source const &)>;
};

template <typename Source, typename Target> struct Operator<Source, Target, std::function<Target(Source const &)>> {
  std::function<Target(Source const &)> func;
  inline Target operator()(Source const &source) const { return func(source); }
  inline friend Target operator>>(Source const &source, Operator accessor) { return accessor.operator()(source); }
};

template <typename Source, typename Target> struct OperatorTraits<std::function<Target(Source const &)>> {
  using type = Operator<Source, Target, std::function<Target(Source const &)>>;
};

template <typename Source, typename Target> struct Operator<Source, Target, Target(Source::*)> {
  Target Source::*field;
  inline Target operator()(Source const &source) const { return source.*field; }
  inline friend Target operator>>(Source const &source, Operator accessor) { return accessor.operator()(source); }
};

template <typename Source, typename Target> struct OperatorTraits<Target(Source::*)> { using type = Operator<Source, Target, Target(Source::*)>; };

template <typename Method> auto makeOperator(Method method) { return typename OperatorTraits<Method>::type{ method }; }

} // namespace utils