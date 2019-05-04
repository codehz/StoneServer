#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

struct CommandRequest {
  std::string sender, content;
};

inline void to_json(rpc::json &j, const CommandRequest &i) {
  j["sender"]  = i.sender;
  j["content"] = i.content;
}

inline void from_json(const rpc::json &j, CommandRequest &i) {
  j.at("sender").get_to(i.sender);
  j.at("content").get_to(i.content);
}

struct CommandAutoCompleteRequest {
  std::string content;
  int position;
};

inline void to_json(rpc::json &j, const CommandAutoCompleteRequest &i) {
  j["content"]  = i.content;
  j["position"] = i.position;
}

inline void from_json(const rpc::json &j, CommandAutoCompleteRequest &i) {
  j.at("content").get_to(i.content);
  j.at("position").get_to(i.position);
}

struct AutoCompleteOption {
  std::string source, title, desc;
  int offset, length, item;
};

inline void to_json(rpc::json &j, const AutoCompleteOption &i) {
  j["source"] = i.source;
  j["title"]  = i.title;
  j["desc"]   = i.desc;
  j["offset"] = i.offset;
  j["length"] = i.length;
  j["item"]   = i.item;
}

inline void from_json(const rpc::json &j, AutoCompleteOption &i) {
  j.at("source").get_to(i.source);
  j.at("title").get_to(i.title);
  j.at("desc").get_to(i.desc);
  j.at("offset").get_to(i.offset);
  j.at("length").get_to(i.length);
  j.at("item").get_to(i.item);
}

struct CommandService : Service {
  Method<std::string, CommandRequest> execute{ "execute" };
  CommandService()
      : Service("command") {
    $(execute);
  }
};

} // namespace api