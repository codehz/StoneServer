#pragma once

#include "std/string.h"

#include <memory>
#include <vector>

struct Enchant {
  static std::vector<std::unique_ptr<Enchant>> *mEnchants;
  void **vtable;
  mcpe::string &getDescriptionId() const;

  /// @vtable Enchant _ZNK7Enchant11getMaxLevelEv
  int getMaxLevel();
};

struct EnchantmentInstance {
  uint type;
  int level;
};

struct ItemEnchants {
  char filler[0x28];

  std::vector<EnchantmentInstance> getEnchants(int slot) const;
};

struct ItemInstance {
  char filler[0x100];

  bool isNull() const;
  int getId() const;
  mcpe::string getName() const;
  mcpe::string getRawNameId() const;
  mcpe::string getCustomName() const;

  ItemEnchants getEnchantsFromUserData() const;
};