#pragma once

#include <minecraft/Player.h>

#include "base_interface.h"
#include "event_emitter.h"

namespace interface {

struct Chat : BaseInterface {
  bool intercept;

  EventEmitter<Player &, std::string const &> onPlayerChat;
  EventEmitter<std::string const &, std::string const &> onChat;
};

} // namespace interface