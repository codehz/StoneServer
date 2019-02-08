#pragma once

#include <functional>
#include <list>

namespace interface {

template <typename T> using identity = T;

template <typename T> class ReferenceHolder {
  T *raw_pointer;
  std::list<std::function<void(T &)>> setNotifyList, unsetNotifyList, updateNotifyList;

public:
  ReferenceHolder(ReferenceHolder const &) = delete;

  inline ReferenceHolder(T *init = nullptr)
      : raw_pointer(init) {}
  inline T *operator=(T *input) {
    if (input == raw_pointer) return input;
    auto &tlist = input ? setNotifyList : unsetNotifyList;
    for (auto fn : tlist) fn(*(input ?: raw_pointer));
    tlist.clear();
    for (auto fn : updateNotifyList) fn(*input);
    return (raw_pointer = input);
  }
  inline T &operator=(T &input) { return *(*this = &input); }
  inline T *operator->() { return raw_pointer; }
  inline T &operator*() { return *raw_pointer; }
  inline T *operator&() { return raw_pointer; }
  inline operator T *() { return raw_pointer; }
  inline operator T &() { return *raw_pointer; }

  template <typename F> inline void operator>>(F const &f) {
    if (raw_pointer)
      f(*raw_pointer);
    else
      setNotifyList.emplace_back(f);
  }
  template <typename F> inline void operator>>=(F const &f) { setNotifyList.emplace_back(f); }
  template <typename F> inline void operator|=(F const &f) { unsetNotifyList.emplace_back(f); }
  template <typename F> inline void operator>=(F const &f) { updateNotifyList.emplace_back(f); }

  template <typename R = T, typename... Params> inline R &generate(Params... params) {
    static R impl{ params... };
    *this = &impl;
    return impl;
  }
};

template <typename T, template <typename> typename Holder = ReferenceHolder> inline Holder<T> &Locator() {
  static Holder<T> ref;
  return ref;
};

template <typename T> struct plain_type { using type = T; };
template <typename T> struct plain_type<T *> { using type = typename plain_type<T>::type; };
template <typename T> struct plain_type<T &> { using type = typename plain_type<T>::type; };
template <typename T> struct plain_type<T &&> { using type = typename plain_type<T>::type; };
template <typename T> struct plain_type<T const> { using type = typename plain_type<T>::type; };
template <typename T> struct plain_type<T volatile> { using type = typename plain_type<T>::type; };

template <typename T> using plain_type_t = typename plain_type<T>::type;

template <typename T, typename R> inline auto FieldRef(R(T::*field)) {
  return [=](T &t) { Locator<plain_type_t<R>>() = t.*field; };
}

template <typename T, typename R> inline auto MethodGet(R (T::*method)()) {
  return [=](T &t) { Locator<plain_type_t<R>>() = (t.*method)(); };
}

template <typename T, typename R> inline auto MethodGet(R (T::*method)() const) {
  return [=](T &t) { Locator<plain_type_t<R>>() = (t.*method)(); };
}

template <typename T, typename R> inline auto MethodGet(R (*method)(T *)) {
  return [=](T &t) { Locator<plain_type_t<R>>() = method(t); };
}

} // namespace interface