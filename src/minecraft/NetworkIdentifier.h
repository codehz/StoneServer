#pragma once

#include <cstddef>
#include <string>

struct NetworkIdentifier {
  char filler[144];
  int getHash() const;
  bool equalsTypeData(NetworkIdentifier const &) const;
  inline bool operator==(NetworkIdentifier const &addr) const { return equalsTypeData(addr); }
};

namespace std {
template <> struct hash<NetworkIdentifier> {
  std::size_t operator()(NetworkIdentifier const &s) const noexcept { return s.getHash(); }
};
} // namespace std
