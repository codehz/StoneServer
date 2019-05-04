#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

template <bool reason = false> struct BlacklistOP { std::string type, content; };

template <> struct BlacklistOP<true> { std::string type, content, reason; };

template <bool reason> inline void to_json(rpc::json &j, const BlacklistOP<reason> &i) {
  j[i.type] = i.content;
  if constexpr (reason) j["reason"] = i.reason;
}

template <bool reason> inline void from_json(const rpc::json &j, BlacklistOP<reason> &i) {
  try {
    if (j.contains("name")) {
      i.type    = "name";
      i.content = j["name"];
    } else if (j.contains("uuid")) {
      i.type    = "uuid";
      i.content = j["uuid"];
    } else if (j.contains("xuid")) {
      i.type    = "xuid";
      i.content = j["xuid"];
    } else {
      i.type = "error";
    }
  } catch (...) { i.type = "error"; }

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