#pragma once

#include "AutoComplete.h"
#include "CommandOrigin.h"
#include "std/string.h"
#include <memory>

struct CommandRegistry {
  // @symbol _ZNK15CommandRegistry22getAutoCompleteOptionsERK13CommandOriginRKSsj
  std::unique_ptr<AutoCompleteInformation> getAutoCompleteOptions(CommandOrigin const &, mcpe::string const &, unsigned int) const;
};