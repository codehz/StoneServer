#include "common.h"

namespace GlobalAPI {
std::vector<void (*)(Local<Object> &, Isolate *, Local<Context> &)> Register::registry;
}