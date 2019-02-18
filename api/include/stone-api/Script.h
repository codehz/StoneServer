#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

struct EventData {
  std::string name, data;
  static inline Buffer write(EventData const &input) { return Buffer::format("%s\n%s", input.name.data(), input.data.data()); }
  static inline EventData read(char const *input) {
    std::istringstream iss{ input };
    EventData event;
    std::getline(iss, event.name);
    std::getline(iss, event.data);
    return event;
  }
  std::string build(std::string xname) const { return xname + "." + name; }
  static inline EventData rebuild(char const *identify, char const *data) { return { strrchr(identify, '.'), data }; }
  static inline std::string build_pattern(std::string const &name) { return name + ".*"; }
  static inline std::string build_pattern(std::string const &name, std::string const &key) { return name + "." + key; }
};

template <typename Side> struct ScriptService : ProxiedService<Side, ScriptService> {
  ProxiedAction<Side, EventData> emit{ "emit" };
  ProxiedPatternBoardcast<Side, EventData> broadcast{ "broadcast" };

  ScriptService()
      : ProxiedService<Side, ScriptService>("script") {
    this->$(emit);
    this->$(broadcast);
  }
};

} // namespace api