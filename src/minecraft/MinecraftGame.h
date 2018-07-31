#pragma once

#include <memory>
#include "App.h"

class Options;

class ClientInstance {

public:

    void _startLeaveGame();

    void _syncDestroyGame();

};

class MinecraftGame : public App {

public:

    char filler [0x4000];

    MinecraftGame(int carg, char** args);

    ~MinecraftGame();

    void requestLeaveGame(bool, bool);

    void update();

    void setRenderingSize(int, int);

    void setUISizeAndScale(int, int, float);

    std::shared_ptr<Options> getPrimaryUserOptions();

    ClientInstance* getPrimaryClientInstance();

    void startLeaveGame();

    void continueLeaveGame();

};
