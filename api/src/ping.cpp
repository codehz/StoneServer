#define API_MODE 1
#include "../include/stone-api/Core.h"
#include <iostream>

std::string GetEnvironmentVariableOrDefault(const std::string &variable_name, const std::string &default_value) {
  const char *value = getenv(variable_name.c_str());
  return value ? value : default_value;
}

#define LOAD_ENV(env, def) static const auto env = GetEnvironmentVariableOrDefault(#env, def)

LOAD_ENV(API_ENDPOINT, "ws+unix://data/api.socket");

int main() {
  using namespace rpcws;
  using namespace api;

  endpoint() = std::make_unique<rpcws::RPC::Client>(std::make_unique<rpcws::client_wsio>(API_ENDPOINT));

  CoreService core;

  endpoint()
      ->start()
      .then<promise<Empty>>([&] {
        std::cout << "connected!" << std::endl;
        return core.ping({});
      })
      .then([](auto) {
        std::cout << "pong!" << std::endl;
        endpoint()->stop();
      })
      .fail([](std::exception const &ex) { std::cerr << typeid(ex).name() << ex.what() << std::endl; });
}