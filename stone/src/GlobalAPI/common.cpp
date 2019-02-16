#include "common.h"

namespace WebAPI {
std::vector<void (*)(Local<Object> &, Isolate *, Local<Context> &)> Register::registry;
}