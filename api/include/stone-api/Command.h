#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

struct CommandRequest {
  std::string sender, content;

  static inline Buffer write(CommandRequest const &input) {
    char *buffer;
    asprintf(&buffer, "%s\n%s", input.sender.data(), input.content.data());
    return { buffer };
  }
  static inline CommandRequest read(char const *input) {
    std::istringstream iss{ input };
    CommandRequest request;
    std::getline(iss, request.sender);
    std::getline(iss, request.content);
    return request;
  }
};

struct CommandAutoCompleteRequest {
  std::string content;
  int position;

  static inline Buffer write(CommandAutoCompleteRequest const &input) {
    char *buffer;
    asprintf(&buffer, "%s\n%d", input.content.data(), input.position);
    return { buffer };
  }
  static inline CommandAutoCompleteRequest read(char const *input) {
    std::istringstream iss{ input };
    CommandAutoCompleteRequest request;
    std::getline(iss, request.content);
    iss >> request.position;
    return request;
  }
};

struct AutoCompleteOption {
  std::string source, title, desc;
  int offset, length, item;

  static inline Buffer write(AutoCompleteOption const &input) {
    char *buffer;
    asprintf(&buffer, "%s\n%s\n%s\n%d %d %d", input.source.data(), input.title.data(), input.desc.data(), input.offset, input.length, input.item);
    return { buffer };
  }
  static inline AutoCompleteOption read(char const *input) {
    std::istringstream iss{ input };
    AutoCompleteOption option;
    std::getline(iss, option.source);
    std::getline(iss, option.title);
    std::getline(iss, option.desc);
    iss >> option.offset >> option.length >> option.item;
    return option;
  }
};

template <typename Side> struct CommandService : ProxiedService<Side> {
  ProxiedMethod<Side, CommandRequest, std::string> execute{ "execute" };
  CommandService()
      : ProxiedService<Side>("command") {
    this->$(execute);
  }
};

} // namespace api