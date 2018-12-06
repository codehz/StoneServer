#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include <stone/hook_helper.h>

namespace patched {

template <typename F> std::string withCommandOutput(F f) {
  using namespace std;
  struct __attribute__((__packed__)) mov {
    char ins_mov = 0xB8;
    ostream *stream;
    char nop = 0x90;
  };
  static_assert(sizeof(mov) == 6);
  stringstream ss;
  auto patch = BUILD_HELPER(TempReplace, mov, 68, "_ZN19CommandOutputSender4sendERK13CommandOriginRK13CommandOutput")(mov{ .stream = &ss });
  f();
  return ss.str();
}

namespace details {
  struct RegisterPatchInit {
    RegisterPatchInit(void (*)());
  };
}

void init();

} // namespace patched