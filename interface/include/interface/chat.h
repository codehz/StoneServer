#pragma once

#include <minecraft/Player.h>

#include "base_interface.h"
#include "event_emitter.h"

namespace interface {

struct Chat : BaseInterface {
  bool intercept;

  EventEmitter<Player &, std::string const &> onPlayerChat;
  std::function<void(std::string const &, std::string const &, std::string const &, std::string const &)> broadcastChat;
  std::function<void(std::string const &, std::string const &, std::string const &, std::string const &)> broadcastAnnouncement;
  std::function<void(std::string const &)> broadcastSystemMessage;
  std::function<void(std::string const &)> broadcastJukebox;
  std::function<void(std::string const &)> broadcastWhisper;
};

} // namespace interface