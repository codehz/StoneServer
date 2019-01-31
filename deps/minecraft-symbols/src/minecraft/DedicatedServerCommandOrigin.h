#pragma once

#include "CommandOrigin.h"
#include "UUID.h"
#include "std/string.h"
#include <array>

class Minecraft;

class DedicatedServerCommandOrigin : public CommandOrigin {

public:
  Minecraft *mc;
  mcpe::string name;

  DedicatedServerCommandOrigin(mcpe::string const &s, Minecraft &m);
};