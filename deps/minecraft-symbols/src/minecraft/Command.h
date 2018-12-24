#pragma once

class CommandOrigin;
class CommandOutput;

struct Command {
  char filler[0x20];
  virtual ~Command();
  /// @skipped
  virtual void execute(CommandOrigin &orig, CommandOutput &outp) = 0;
  Command();
};