#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

template <bool reason = false> struct BlacklistOP { std::string type, content; };

template <> struct BlacklistOP<true> { std::string type, content, reason; };

template <bool reason> inline void to_json(rpc::json &j, const BlacklistOP<reason> &i) {
  j["type"]    = i.type;
  j["content"] = i.content;
  if constexpr (reason) j["reason"] = i.reason;
}

template <bool reason> inline void from_json(const rpc::json &j, BlacklistOP<reason> &i) {
  j.at("type").get_to(i.type);
  j.at("content").get_to(i.content);
  if constexpr (reason) j.at("reason").get_to(i.reason);
}

struct BlacklistService : Service {
  Action<BlacklistOP<true>> add{ "add" };
  Action<BlacklistOP<false>> remove{ "remove" };
  Action<BlacklistOP<true>> kick{ "kick" };
  Method<std::vector<BlacklistOP<true>>, Empty> fetch{ "fetch" };

  BlacklistService()
      : Service("blacklist") {
    $(add);
    $(remove);
    $(kick);
    $(fetch);
  }
};

} // namespace api