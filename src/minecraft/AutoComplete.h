#pragma once

#include "std/string.h"
#include <vector>

struct CommandItem {
  int flag, id;
};

struct AutoCompleteOption {
  mcpe::string source, title, description;
  int offset, eat, tail;
  CommandItem item;
  bool flag;
};

struct AutoCompleteInformation {
  std::vector<AutoCompleteOption> list;
};
