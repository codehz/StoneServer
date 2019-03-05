#pragma once

#include <minecraft/ItemInstance.h>
#include <minecraft/Player.h>

#include "base_interface.h"
#include "event_emitter.h"

namespace interface {

struct Policy : BaseInterface {
  EventEmitter<Player *, std::string const &, bool &> checkAbility;
  EventEmitter<Player *, BlockPos const &, bool &> checkDestroy;
  EventEmitter<Player *, BlockPos const &, bool &> checkBuild;
  EventEmitter<Player *, ItemInstance &, bool &> checkUse;
  EventEmitter<Player *, ItemInstance &, BlockPos const &, Vec3 const &, bool &> checkUseOn;
  EventEmitter<Player *, Actor &, Vec3 const &, bool &> checkInteract;
  EventEmitter<Player *, Actor &, bool &> checkAttack;
};

} // namespace interface