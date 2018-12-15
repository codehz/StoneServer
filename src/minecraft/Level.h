#pragma once

#include <vector>
#include <memory>
#include "Player.h"
#include "UUID.h"
#include "std/string.h"
#include "std/function.h"
#include "EventResult.h"

class ServerLevelEventListener {};

class ServerLevelEventCoordinator {
    std::vector<ServerLevelEventListener *> listeners;
    std::vector<mcpe::function<EventResult (ServerLevelEventListener *)>> handlers;
    char filler[36-28];
};

class Level {

public:
    static unsigned int createRandomSeed();

    ServerLevelEventCoordinator*& _getServerLevelEventCoordinator();

    void _setServerLevelEventCoordinator(std::unique_ptr<ServerLevelEventCoordinator, std::default_delete<ServerLevelEventCoordinator>> &&);
};