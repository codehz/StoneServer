#pragma once

#include "event_emitter.h"
#include "base_interface.h"

namespace interface {

struct Tick : BaseInterface {
  float tps;

  EventEmitter<> tick;
};

} // namespace interface