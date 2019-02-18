#pragma once

#include <functional>
#include <list>
#include <type_traits>

namespace interface {

template <typename... Params> class EventEmitter {
  std::list<std::function<void(std::add_lvalue_reference_t<std::add_const_t<Params>>...)>> handlers;

public:
  inline EventEmitter() {}
  EventEmitter(EventEmitter const &) = delete;
  EventEmitter(EventEmitter &&)      = delete;

  EventEmitter &operator=(EventEmitter const &) = delete;
  EventEmitter &operator=(EventEmitter &&) = delete;

  void operator()(std::add_lvalue_reference_t<std::add_const_t<Params>>... params) const {
    for (auto handler : handlers) handler(params...);
  }

  void operator>>(std::function<void(std::add_lvalue_reference_t<std::add_const_t<Params>>...)> handler) {
    handlers.push_back(handler);
  }
};

} // namespace interface