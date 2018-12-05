#pragma once
#include <cstddef>
#include <iostream>
#include <locale>
#include <sqlite3.h>
#include <string>

#include <mcpelauncher/path_helper.h>

namespace uintl {
char const *gettext(char const *inp);
template <char... X> char const *operator""_intl_in() {
  static char data[] = { X..., 0 };
  static std::string converted = gettext(data);
  return converted.c_str();
}
template <typename T, T... X> char const *operator""_intl() { return operator""_intl_in<X...>(); }
void intl_domain(char const *domain);
} // namespace uintl