#pragma once

#include "CommandOrigin.h"
#include "std/string.h"

class Minecraft;

class AutomationPlayerCommandOrigin : public CommandOrigin {
  char filler[0x100];

public:
  AutomationPlayerCommandOrigin(mcpe::string const &, Player &);

  void setPermissionLevel(int level) {
    *((int *)this + 10) = level;
  }
};