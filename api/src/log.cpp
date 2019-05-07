#define API_MODE 1
#include "../include/stone-api/Command.h"
#include "../include/stone-api/Core.h"
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <readline/history.h>
#include <readline/readline.h>
#include <thread>

std::string GetEnvironmentVariableOrDefault(const std::string &variable_name, const std::string &default_value) {
  const char *value = getenv(variable_name.c_str());
  return value ? value : default_value;
}

#define LOAD_ENV(env, def) static const auto env = GetEnvironmentVariableOrDefault(#env, def)

LOAD_ENV(API_ENDPOINT, "ws+unix://data/api.socket");

std::string_view print_level(int level) {
  switch (level) {
  case 0: return "T";
  case 1: return "D";
  case 2: return "I";
  case 3: return "W";
  case 4: return "E";
  default: return "U";
  }
}

int main() {
  using namespace rpcws;
  using namespace api;

  endpoint() = std::make_unique<rpcws::RPC::Client>(std::make_unique<rpcws::client_wsio>(API_ENDPOINT));

  CoreService core;

  endpoint()
      ->start()
      .then([&] { core.log >> [](auto entry) { std::cout << print_level(entry.level) << " " << entry.content << std::endl; }; })
      .fail([&](auto) { endpoint()->stop(); })();
}