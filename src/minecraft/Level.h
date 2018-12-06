#pragma once

#include <vector>
#include <memory>
#include "Player.h"
#include "UUID.h"
#include "std/string.h"

class ServerLevelEventCoordinator {};

class Level {

public:
    static unsigned int createRandomSeed();

    std::vector<Player *> *getUsers();

    void _setServerLevelEventCoordinator(std::unique_ptr<ServerLevelEventCoordinator, std::default_delete<ServerLevelEventCoordinator>> &&);
};