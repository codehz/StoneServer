#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

struct NormalMessage {
  std::string sender, content;
};

inline void to_json(rpc::json &j, const NormalMessage &i) {
  j["sender"]  = i.sender;
  j["content"] = i.content;
}

inline void from_json(const rpc::json &j, NormalMessage &i) {
  j.at("sender").get_to(i.sender);
  j.at("content").get_to(i.content);
}

struct ChatService : Service {
  Action<NormalMessage> send{ "send" };
  Broadcast<NormalMessage> recv{ "recv" };
  Action<std::string> raw{ "raw" };

  ChatService()
      : Service("chat") {
    $(send);
    $(recv);
    $(raw);
  }
};

} // namespace api