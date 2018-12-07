#pragma once

#include "std/string.h"

class IPackTelemetry {};

class IMinecraftEventing : public IPackTelemetry {
public:
};

class MinecraftEventing : public IMinecraftEventing {

public:

    char filler[0x100];

    MinecraftEventing(mcpe::string const& str);

    void init();

};