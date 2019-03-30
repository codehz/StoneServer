#pragma once

#include "std/string.h"

namespace mce {

class UUID {

public:
  static mce::UUID *EMPTY;
  static mce::UUID fromString(mcpe::string const &);
  uint64_t high, low;
  mcpe::string asString() const;
  bool isEmpty() const;
  inline bool operator==(mce::UUID const &rhs) { return high == rhs.high && low == rhs.low; }
};

}