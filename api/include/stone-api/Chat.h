#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

struct NormalMessage {
  std::string sender, content;

  static inline Buffer write(NormalMessage const &input) {
    char *buffer;
    asprintf(&buffer, "%s\n%s", input.sender.data(), input.content.data());
    return { buffer };
  }
  static inline NormalMessage read(char const *input) {
    std::istringstream iss{ input };
    NormalMessage message;
    std::getline(iss, message.sender);
    std::getline(iss, message.content);
    return message;
  }
};

template <typename Side> struct ChatService : ProxiedService<Side> {
  ProxiedAction<Side, NormalMessage> send{ "send" };
  ProxiedBoardcast<Side, NormalMessage> recv{ "recv" };
  ProxiedAction<Side, std::string> raw{ "raw" };

  ChatService()
      : ProxiedService<Side>("chat") {
    this->$(send);
    this->$(recv);
    this->$(raw);
  }
};

} // namespace api