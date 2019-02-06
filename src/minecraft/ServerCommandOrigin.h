#pragma once

#include "CommandOrigin.h"
#include "Level.h"
#include "UUID.h"
#include "std/string.h"
#include <array>

class Minecraft;
using ServerLevel = Level;

class ServerCommandOrigin : public CommandOrigin {

public:
  Minecraft *mc;
  mcpe::string name;

  ServerCommandOrigin(mcpe::string const &s, ServerLevel &level);
};