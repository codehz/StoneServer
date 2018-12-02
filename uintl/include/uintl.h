#include <cstddef>
#include <iostream>
#include <locale>
#include <sqlite3.h>
#include <string>

#include <mcpelauncher/path_helper.h>

namespace uintl {
char const *operator""_intl(char const *inp, std::size_t);
char const *gettext(char const *inp);
void intl_domain(char const *domain);
} // namespace uintl