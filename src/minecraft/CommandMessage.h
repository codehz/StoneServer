#pragma once

#include "std/string.h"

class CommandOrigin;

class CommandMessage {
public:
  mcpe::string getMessage(CommandOrigin const&) const;
};