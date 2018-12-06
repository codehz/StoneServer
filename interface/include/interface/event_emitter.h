#pragma once

#include <functional>
#include <list>
#include <type_traits>

namespace interface {

template <typename... Params> class EventEmitter {
  std::list<std::function<void(std::add_const_t<std::add_lvalue_reference_t<Params>>...)>> handlers;

public:
  void operator()(std::add_const_t<std::add_lvalue_reference_t<Params>>... params) const {
    for (auto handler : handlers) handler(params...);
  }

  void operator>>(std::function<void(std::add_const_t<std::add_lvalue_reference_t<Params>>...)> handler) { handlers.push_back(handler); }
};

} // namespace interface