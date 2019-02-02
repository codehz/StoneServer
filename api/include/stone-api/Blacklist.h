#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

struct BlacklistOP {
  std::string op, content;

  static inline Buffer write(BlacklistOP const &input) {
    char *buffer;
    asprintf(&buffer, "%s\n%s", input.op.data(), input.content.data());
    return { buffer };
  }
  static inline BlacklistOP read(char const *input) {
    std::istringstream iss{ input };
    BlacklistOP op;
    std::getline(iss, op.op);
    std::getline(iss, op.content);
    return op;
  }
};

template <typename Side> struct BlacklistService : ProxiedService<Side> {
  ProxiedAction<Side, BlacklistOP> add{ "add" }, remove{ "remove" }, kick{ "kick" };
  BlacklistService()
      : ProxiedService<Side>("blacklist") {
    this->$(add);
    this->$(remove);
    this->$(kick);
  }
};

} // namespace api