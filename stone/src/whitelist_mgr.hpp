#pragma once

#include <fstream>
#include <minecraft/Whitelist.h>
#include <minecraft/json.h>

struct WhitelistManager {
  const std::string path;
  Whitelist list;
  WhitelistManager(std::string const &path)
      : path(path)
      , list([] {}) {
    reload();
    save();
  }

  void reload() {
    Json::Reader reader;
    Json::Value value(Json::nullValue);
    std::ifstream ifs(path);
    if (!ifs) return;
    reader.parse(ifs, value, false);
    list.deserialize(value);
  }

  void save() {
    Json::StyledWriter writer;
    Json::Value value(Json::nullValue);
    std::ofstream ofs(path);
    list.serialize(value);
    ofs << writer.write(value);
  }
};