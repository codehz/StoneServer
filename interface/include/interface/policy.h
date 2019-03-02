#pragma once

#include <minecraft/Player.h>

#include "base_interface.h"
#include "event_emitter.h"

namespace interface {

struct Policy : BaseInterface {
  EventEmitter<Player *, std::string const &, bool &> checkAbility;
};

} // namespace interface