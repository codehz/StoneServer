#pragma once
#include <cstddef>
#include <iostream>
#include <locale>
#include <sqlite3.h>
#include <string>

#include <mcpelauncher/path_helper.h>

namespace uintl {
char const *operator""_intl(char const *inp, std::size_t);
#ifdef VSCODE_WORKAROUND
char const *operator""_static_intl(char const *inp, std::size_t);
#else
template <char... X> char const *operator""_static_intl_in() {
  static char data[] = { X..., 0 };
  static std::string converted = operator""_intl(data, -1);
  return converted.c_str();
}
template <typename T, T... X> char const *operator""_static_intl() { return operator""_static_intl_in<X...>(); }
#endif
char const *gettext(char const *inp);
void intl_domain(char const *domain);
} // namespace uintl