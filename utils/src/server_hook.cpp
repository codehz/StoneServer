#include <stone/server_hook.h>

std::vector<std::tuple<const char *, void *, void **>> &GetServerHookRegistry() {
  static std::vector<std::tuple<const char *, void *, void **>> registry;
  return registry;
}