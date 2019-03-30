#pragma once

#include "UUID.h"
#include "std/string.h"

#include <mutex>
#include <vector>

struct Blacklist {
  struct Entry {
    mce::UUID uuid;
    mcpe::string name;
    mcpe::string reason;
    int duration;
  };

  std::vector<Entry> vec;
  std::mutex mtx;
};