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
  case 0: return "\033[90mT";
  case 1: return "\033[33mD";
  case 2: return "\033[32mI";
  case 3: return "\033[31mW";
  case 4: return "\033[91mE";
  default: return "\033[101mU";
  }
}

int main() {
  using namespace rpcws;
  using namespace api;

  endpoint() = std::make_unique<rpcws::RPC::Client>(std::make_unique<rpcws::client_wsio>(API_ENDPOINT));

  CoreService core;
  CommandService command;

  bool ready = false;
  bool error = false;
  bool wait  = false;
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
        });
  });

  worker.detach();

  {
    std::unique_lock lk{ mtx };
    cv.wait(lk, [&] { return ready; });
    if (error) return EXIT_FAILURE;
  }

  ready = false;

  core.log >> [&](LogEntry const &entry) {
    std::unique_lock lk{ mtx };
    int need_hack = (rl_readline_state & RL_STATE_READCMD) > 0;
    char *saved_line;
    int saved_point;
    if (need_hack) {
      saved_point = rl_point;
      saved_line  = rl_copy_text(0, rl_end);
      rl_save_prompt();
      rl_replace_line("", 0);
      rl_redisplay();
    }

    std::cout << print_level(entry.level) << " " << entry.content << "\033[0m" << std::endl;

    if (need_hack) {
      rl_restore_prompt();
      rl_replace_line(saved_line, 0);
      rl_point = saved_point;
      rl_redisplay();
      free(saved_line);
    }
  };

  char *line;
  while ((line = readline("stone> "))) {
    ready = false;
    command.execute({ "cli", line })
        .then([&](auto result) {
          std::unique_lock lk{ mtx };
          std::cout << result;
          ready = true;
          cv.notify_all();
        })
        .fail([&](auto) {
          std::unique_lock lk{ mtx };
          error = true;
          ready = true;
          cv.notify_all();
        });
    std::unique_lock lk{ mtx };
    cv.wait(lk, [&] { return ready; });
    if (error) return EXIT_FAILURE;
  }
}