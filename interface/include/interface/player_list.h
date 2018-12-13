#pragma once

#include <minecraft/Player.h>
#include <set>

#include "event_emitter.h"
#include "base_interface.h"

namespace interface {

struct PlayerList : BaseInterface {
  std::set<Player *> set;
  EventEmitter<Player &> onPlayerAdded;
  EventEmitter<Player &> onPlayerRemoved;
};

} // namespace interface