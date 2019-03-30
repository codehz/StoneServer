#pragma once

#include <minecraft/NetworkIdentifier.h>
#include <minecraft/UUID.h>

#include <variant>

#include "base_interface.h"
#include "event_emitter.h"

namespace interface {

struct Blacklist : BaseInterface {
  virtual void add(mce::UUID const &, std::string const &)                                                               = 0;
  virtual void add(std::string const &, std::string const &)                                                             = 0;
  virtual void remove(mce::UUID const &)                                                                                 = 0;
  virtual void remove(std::string const &)                                                                               = 0;
  virtual void kick(NetworkIdentifier const &, std::string const &)                                                      = 0;
  virtual void forEach(std::function<void(std::variant<mce::UUID, std::string> const &, std::string const &)> const &fn) = 0;
};

} // namespace interface