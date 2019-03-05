#pragma once

#include "UUID.h"
#include "std/string.h"
#include "types.h"
#include <array>
#include <memory>

enum class CommandOriginType {
  Player           = 0,
  Block            = 1,
  MinecartBlock    = 2,
  DevConsole       = 3,
  Test             = 4,
  AutomationPlayer = 5,
  ClientAutomation = 6,
  DedicatedServer  = 7,
  Actor            = 8,
  Virtual          = 9,
  GameArgument     = 10,
  ActorServer      = 11,
};

struct Actor;

class CommandOrigin {
public:
  void **vtable;
  mce::UUID uuid;

  /// @vtable PlayerCommandOrigin _ZNK19PlayerCommandOrigin7getNameEv
  mcpe::string getName();
  /// @vtable PlayerCommandOrigin _ZNK19PlayerCommandOrigin16getBlockPositionEv
  BlockPos getBlockPosition();
  /// @vtable PlayerCommandOrigin _ZNK19PlayerCommandOrigin16getWorldPositionEv
  Vec3 getWorldPosition();
  /// @vtable PlayerCommandOrigin _ZNK19PlayerCommandOrigin5cloneEv
  std::unique_ptr<CommandOrigin> clone();
  /// @vtable PlayerCommandOrigin _ZNK19PlayerCommandOrigin13getOriginTypeEv
  CommandOriginType getOriginType();
  /// @vtable PlayerCommandOrigin _ZNK19PlayerCommandOrigin9getEntityEv
  Actor *getEntity();
  /// @vtable PlayerCommandOrigin _ZNK19PlayerCommandOrigin19getPermissionsLevelEv
  unsigned char getPermissionLevel();

  mce::UUID const &getUUID() const;
};

struct Player;

class PlayerCommandOrigin : public CommandOrigin {
  char filler[0x50];

public:
  PlayerCommandOrigin(Player &);
};