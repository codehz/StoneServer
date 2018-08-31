#pragma once

#include "UUID.h"

struct ContentIdentity {
    mce::UUID uuid;
    bool b = false;

    static ContentIdentity* EMPTY;
};