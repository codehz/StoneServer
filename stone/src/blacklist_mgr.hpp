#pragma once

#include <fstream>
#include <interface/blacklist.h>
#include <interface/locator.hpp>
#include <json.hpp>
#include <log.h>
#include <minecraft/UUID.h>
#include <string>
#include <variant>

struct BlacklistManager {
  const std::string path;

  inline BlacklistManager(std::string const &path)
      : path(path) {
    using namespace interface;
    Locator<interface::Blacklist>() >> [this](auto &) { reload(); };
  }

  inline void reload() {
    using namespace interface;
    using namespace nlohmann;
    std::ifstream ifs{ path };
    if (!ifs) return;
    try {
      for (auto item : json::parse(ifs)) {
        auto reason = item.at("reason").get<std::string>();
        if (item.contains("uuid")) {
          Locator<interface::Blacklist>()->add(mce::UUID::fromString(item.at("uuid").get<std::string>()), reason);
        } else if (item.contains("xuid")) {
          Locator<interface::Blacklist>()->add(item.at("xuid").get<std::string>(), reason);
        }
      }
    } catch (...) {
      Log::error("Blacklist", "Failed to load %s", path.c_str());
      return;
    }
  }

  inline void save() {
    using namespace interface;
    using namespace nlohmann;
    Log::info("Blacklist", "Saving to %s", path.c_str());
    json arr = json::array();
    Locator<interface::Blacklist>()->forEach([&](std::variant<mce::UUID, std::string> const &value, std::string reason) {
      json obj = json::object({ { "reason", reason } });
      if (auto puuid = std::get_if<mce::UUID>(&value); puuid)
        obj["uuid"] = puuid->asString().std();
      else if (auto pxuid = std::get_if<std::string>(&value); pxuid)
        obj["xuid"] = *pxuid;
      arr.push_back(obj);
    });
    std::ofstream ofs{ path };
    ofs << arr;
  }

  inline ~BlacklistManager() {
    using namespace interface;
    if (Locator<interface::Blacklist>()) save();
  }
};