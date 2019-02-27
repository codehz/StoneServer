#pragma once

#include "Tag.h"

struct Block {
  char filler[12];
  CompoundTag tag;
  CompoundTag tag2;
  char filler2[0x200];
};