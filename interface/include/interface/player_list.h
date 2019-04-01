#pragma once

#include <minecraft/Player.h>
#include <set>

#include "base_interface.h"
#include "event_emitter.h"

namespace interface {

struct PlayerList : BaseInterface {
  std::set<Player *> set;
  EventEmitter<Player &> onPlayerAdded;
  EventEmitter<Player &> onPlayerRemoved;
};

} // namespace interface