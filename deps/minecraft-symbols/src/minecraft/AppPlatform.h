#pragma once

#include "std/string.h"
#include "fix.h"

class Vec2;

class AppPlatform {

public:
    /// @symbol _ZTV11AppPlatform
    static XPointer myVtable;

    /// @symbol _ZN14ServiceLocatorI11AppPlatformE15mDefaultServiceE
    static AppPlatform** instance;

    void** vtable;
    char filler[0xA0 - sizeof(void**)];
    // A0
    int hardwareTier;
    char filler2[0x1000];

    AppPlatform();

    void _fireAppFocusGained();

    void initialize();

    void teardown();

    void showKeyboard(mcpe::string const&, int, bool, bool, bool, int, Vec2 const&);

    void hideKeyboard();

    bool isKeyboardVisible();

};
