#pragma once

#include <minecraft/ItemInstance.h>
#include <minecraft/Player.h>
#include <minecraft/Block.h>

#include "base_interface.h"
#include "event_emitter.h"

namespace interface {

struct Policy : BaseInterface {
  EventEmitter<Player *, std::string const &, bool &> checkAbility;
  EventEmitter<Player *, BlockPos const &, bool &> checkDestroy;
  EventEmitter<Player *, BlockPos const &, bool &> checkBuild;
  EventEmitter<Player *, ItemStack &, bool &> checkUse;
  EventEmitter<Player *, ItemStack &, BlockPos const &, Vec3 const &, Block &, bool &> checkUseOn;
  EventEmitter<Player *, Actor &, Vec3 const &, bool &> checkInteract;
  EventEmitter<Player *, Actor &, bool &> checkAttack;
  EventEmitter<Player *, Block &, BlockPos const &, bool &> checkUseBlock;
};

} // namespace interface