#pragma once

#include "locator.hpp"

#include <functional>
#include <list>

namespace interface {
struct BaseInterface {
  BaseInterface() {};
  BaseInterface(BaseInterface const &) = delete;
  BaseInterface(BaseInterface &&)      = delete;
  BaseInterface &operator=(BaseInterface const &) = delete;
  BaseInterface &operator=(BaseInterface &&) = delete;
  inline virtual ~BaseInterface(){};
};

} // namespace interface