#pragma once

#include <minecraft/UUID.h>

#include "base_interface.h"
#include "event_emitter.h"

namespace interface {

struct Blacklist : BaseInterface {
  virtual void add(mce::UUID const &, std::string const &)   = 0;
  virtual void add(std::string const &, std::string const &) = 0;
  virtual void remove(mce::UUID const &)                     = 0;
  virtual void remove(std::string const &)                   = 0;
};

} // namespace interface