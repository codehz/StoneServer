#pragma once

#include <map>
#include <minecraft/Player.h>

#include "base_interface.h"
#include "event_emitter.h"

namespace interface {

struct ModalForm : BaseInterface {
  EventEmitter<unsigned, Player *, std::string> recv;
  virtual void send(Player *, unsigned, std::string const &) = 0;
};

} // namespace interface