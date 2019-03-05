#pragma once

#include "std/string.h"

struct ItemInstance {
  char filler[0x100];

  bool isNull() const;
  int getId() const;
  mcpe::string getName() const;
  mcpe::string getRawNameId() const;
  mcpe::string getCustomName() const;
};