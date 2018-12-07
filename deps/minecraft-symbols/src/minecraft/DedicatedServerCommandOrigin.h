#pragma once

#include "std/string.h"
#include "CommandOrigin.h"

class Minecraft;

class DedicatedServerCommandOrigin : public CommandOrigin {

public:

    char filler[0x20];

    DedicatedServerCommandOrigin(mcpe::string const& s, Minecraft& m);

};