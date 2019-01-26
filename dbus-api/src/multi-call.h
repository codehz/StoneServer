#pragma once

#include <map>
#include <simppl/dispatcher.h>
#include <string>
#include <string_view>

extern simppl::dbus::Dispatcher disp;

void xassert(bool value, int code, char const *message);

using MainFn = int (*)(int, char **);

class MultiCallRegistry {
  static std::map<std::string, MainFn, std::less<>> list;

public:
  static MainFn find(std::string_view const &path);

  MultiCallRegistry(std::string_view const &name, MainFn func) { list.emplace(name, func); }
};

#define DEF_MAIN(name)                                                                                                                               \
  static int xmain(int, char **);                                                                                                                    \
  static MultiCallRegistry registry{ name, xmain };                                                                                                  \
  int xmain(int argc, char *argv[])
