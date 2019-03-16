#pragma once

#include "types.h"

struct Biome;
struct Block;

struct BlockSource {
  Biome *getBiome(BlockPos const &);
  Block *getBlock(BlockPos const &) const;
  Block *getExtraBlock(BlockPos const &) const;
  void setBlock(int x, int y, int z, Block const &block, int sub);
};