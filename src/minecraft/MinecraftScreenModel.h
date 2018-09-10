#pragma once

#include <functional>
#include "Social.h"

class ClientInstance;

class MinecraftScreenModel {

public:
    char filler[0x10];
    ClientInstance* clientInstance;

    /// @symbol _ZN20MinecraftScreenModel32navigateToXblConsoleSignInScreenERKSsS1_
    void navigateToXblConsoleSignInScreen(mcpe::string const&, mcpe::string const&);

    /// @symbol _ZN20MinecraftScreenModel41navigateToXblConsoleSignInSucceededScreenERKN6Social12SignInResultESt8functionIFvS1_EEb
    void navigateToXblConsoleSignInSucceededScreen(Social::SignInResult const&, mcpe::function<void (Social::SignInResult)>, bool);

};