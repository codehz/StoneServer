#pragma once

#include <fstream>
#include <minecraft/Whitelist.h>
#include <minecraft/json.h>

struct WhitelistManager {
  const std::string path;
  Whitelist list;
  inline WhitelistManager(std::string const &path)
      : path(path)
      , list([] {}) {
    reload();
    save();
  }

  inline void reload() {
    Json::Reader reader;
    Json::Value value;
    std::ifstream ifs(path);
    if (!ifs) return;
    reader.parse(ifs, value, false);
    list.deserialize(value);
  }

  inline void save() {
    Json::StyledWriter writer;
    Json::Value value;
    std::ofstream ofs(path);
    list.serialize(value);
    ofs << writer.write(value);
  }
};