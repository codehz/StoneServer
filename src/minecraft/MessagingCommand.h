#pragma once

class CommandOrigin;
class CommandOutput;

class MessagingCommand {
  char fill[20];
public:
  bool checkChatPermissions(CommandOrigin const &, CommandOutput &) const;
};