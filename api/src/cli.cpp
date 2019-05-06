#define API_MODE 1
#include "../include/stone-api/Command.h"
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

int main() {
  using namespace rpcws;
  using namespace api;

  endpoint() = std::make_unique<rpcws::RPC::Client>(std::make_unique<rpcws::client_wsio>(API_ENDPOINT));

  CommandService command;

  bool ready = false;
  bool error = false;
  std::mutex mtx;
  std::condition_variable cv;

  std::thread worker([&] {
    endpoint()
        ->start()
        .then([&] {
          std::unique_lock lk{ mtx };
          ready = true;
          cv.notify_all();
        })
        .fail([&](auto) {
          std::unique_lock lk{ mtx };
          error = true;
          ready = true;
          cv.notify_all();
        })();
  });

  worker.detach();

  {
    std::unique_lock lk{ mtx };
    cv.wait(lk, [&] { return ready; });
    if (error) return EXIT_FAILURE;
  }

  ready = false;

  char *line;
  while ((line = readline("stone> "))) {
    command.execute({ "cli", line })
        .then([&](auto result) {
          std::cout << result;
          std::unique_lock lk{ mtx };
          ready = true;
          cv.notify_all();
        })
        .fail([&](auto) {
          std::unique_lock lk{ mtx };
          error = true;
          ready = true;
          cv.notify_all();
        })();
    std::unique_lock lk{ mtx };
    cv.wait(lk, [&] { return ready; });
    if (error) return EXIT_FAILURE;
  }
}