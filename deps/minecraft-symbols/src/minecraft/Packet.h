#pragma once

struct __attribute__((packed)) Packet {
  /// @symbol _ZTV6Packet
  static void *myVtable;
  void **vtable;       // 0
  int unk4, unk2;      // 4, 8
  unsigned char subId; // 12
  void *handleChunk;   // 16
};