#pragma once

#include <minecraft/Player.h>
#include <vector>

#include "event_emitter.h"
#include "base_interface.h"

namespace interface {

struct PlayerList : BaseInterface {
  std::vector<Player *> *list;
  EventEmitter<Player *> onPlayerAdded;
  EventEmitter<Player *> onPlayerRemoved;
};

} // namespace interface