#pragma once

#include "EventResult.h"
#include "Player.h"
#include "UUID.h"
#include "std/function.h"
#include "std/string.h"
#include <memory>
#include <vector>

class ServerLevelEventListener {};

class ServerLevelEventCoordinator {
  std::vector<ServerLevelEventListener *> listeners;
  std::vector<mcpe::function<EventResult(ServerLevelEventListener *)>> handlers;
  char filler[36 - 28];
};

class Player;

class Level {

public:
  static unsigned int createRandomSeed();

  ServerLevelEventCoordinator *&_getServerLevelEventCoordinator();

  void _setServerLevelEventCoordinator(std::unique_ptr<ServerLevelEventCoordinator, std::default_delete<ServerLevelEventCoordinator>> &&);

  void suspendPlayer(Player &);
  void resumePlayer(Player &);

  BlockPos const &getDefaultSpawn() const;
  void setDefaultSpawn(BlockPos const &);
  Player *getPlayer(const std::string &name) const;
};