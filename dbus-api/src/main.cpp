#include "multi-call.h"
#include <filesystem>
#include <string_view>

std::map<std::string, MainFn, std::less<>> MultiCallRegistry::list;

MainFn MultiCallRegistry::find(std::string_view const &name) {
  std::filesystem::path path{ name };
  std::string filename = path.filename().string();
  if (filename.compare(0, 9, "dbus-api-") != 0) return nullptr;
  auto it = list.find(filename.substr(9));
  if (it != list.end()) { return it->second; }
  return nullptr;
}

int main(int argc, char *argv[]) {
  auto fn = MultiCallRegistry::find(argv[0]);
  if (fn) return fn(argc, argv);
  fprintf(stderr, "%s is not implemented!\n", argv[0]);
  return 1;
}