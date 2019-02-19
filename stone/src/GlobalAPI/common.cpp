#include "common.h"

namespace GlobalAPI {
std::vector<void (*)(Local<ObjectTemplate> &, Isolate *)> Register::registry;
}