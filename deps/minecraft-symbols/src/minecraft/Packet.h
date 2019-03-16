#pragma once

#include "fix.h"

struct Packet {
  /// @symbol _ZTV6Packet
  static XPointer myVtable;
  /// @symbol _ZTV29ServerToClientHandshakePacket
  static XPointer vt_serverToClientHandshake;
  void **vtable;       // 0
  int unk4, unk2;      // 4, 8
  unsigned char subId; // 12
  void *handleChunk;   // 16
};