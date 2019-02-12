#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

template <bool reason = false> struct BlacklistOP {
  std::string type, content;

  static inline Buffer write(BlacklistOP const &input) { return Buffer::format("%s\n%s", input.type.data(), input.content.data()); }
  static inline BlacklistOP read(char const *input) {
    std::istringstream iss{ input };
    BlacklistOP op;
    std::getline(iss, op.type);
    std::getline(iss, op.content);
    return op;
  }
};

template <> struct BlacklistOP<true> {
  std::string type, content, reason;

  static inline Buffer write(BlacklistOP const &input) {
    return Buffer::format("%s\n%s\n%s", input.type.data(), input.content.data(), input.reason.data());
  }
  static inline BlacklistOP read(char const *input) {
    std::istringstream iss{ input };
    BlacklistOP op;
    std::getline(iss, op.type);
    std::getline(iss, op.content);
    std::getline(iss, op.reason);
    return op;
  }
};

template <typename Side> struct BlacklistService : ProxiedService<Side, BlacklistService> {
  ProxiedAction<Side, BlacklistOP<true>> add{ "add" };
  ProxiedAction<Side, BlacklistOP<false>> remove{ "remove" };
  ProxiedAction<Side, BlacklistOP<true>> kick{ "kick" };

  BlacklistService()
      : ProxiedService<Side, BlacklistService>("blacklist") {
    this->$(add);
    this->$(remove);
    this->$(kick);
  }
};

} // namespace api