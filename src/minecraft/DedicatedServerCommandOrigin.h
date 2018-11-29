#pragma once

#include "std/string.h"

class Minecraft;

class CommandOrigin {
};

class DedicatedServerCommandOrigin : public CommandOrigin {

public:

    char filler[0x20];

    DedicatedServerCommandOrigin(mcpe::string const& s, Minecraft& m);

};