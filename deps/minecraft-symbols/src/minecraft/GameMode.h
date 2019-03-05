#pragma once

#include "fix.h"
#include "Player.h"
#include "types.h"

struct GameMode {
  /// @symbol _ZTV8GameMode
  static XPointer vtable;
  Player *player;
  char filler[0x100];

  virtual ~GameMode();
};