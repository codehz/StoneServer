#pragma once

#include <memory>
#include "std/function.h"
#include "App.h"

class Options;
class ClientInstance;

class MinecraftGame : public App {

public:

    char filler [0x4000];

    MinecraftGame(int carg, char** args);

    ~MinecraftGame();

    bool isInGame() const;

    void requestLeaveGame(bool, bool);

    void update();

    void setRenderingSize(int, int);

    void setUISizeAndScale(int, int, float);

    /// @symbol _ZN13MinecraftGame24doPrimaryClientReadyWorkESt8functionIFvvEE
    void doPrimaryClientReadyWork(mcpe::function<void ()>);

    std::shared_ptr<Options> getPrimaryUserOptions();

    ClientInstance* getPrimaryClientInstance();

    void startLeaveGame();

    void continueLeaveGame();

    void setTextboxText(mcpe::string const&, int);

};
