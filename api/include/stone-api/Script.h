#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

struct EventData {
  std::string name, data;
};

inline void to_json(rpc::json &j, const EventData &i) {
  j["name"] = i.name;
  j["data"] = i.data;
}

inline void from_json(const rpc::json &j, EventData &i) {
  j.at("name").get_to(i.name);
  j.at("data").get_to(i.data);
}

struct ScriptService : Service {
  Action<EventData> emit{ "emit" };
  Broadcast<EventData> broadcast{ "broadcast" };

  ScriptService()
      : Service("script") {
    $(emit);
    $(broadcast);
  }
};

} // namespace api