#pragma once

#include "event_emitter.h"
#include "base_interface.h"

namespace interface {

struct Tick : BaseInterface {
  unsigned tps;
};

} // namespace interface