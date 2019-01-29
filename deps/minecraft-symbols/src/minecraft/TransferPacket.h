#pragma once

#include "Packet.h"
#include "std/string.h"

struct TransferPacket : Packet {
  /// @symbol _ZTV14TransferPacket
  static void *myVtable;
  mcpe::string host;
  short port;
  TransferPacket(mcpe::string host, short port)
      : host(host)
      , port(port) {
    vtable = (void **)myVtable + 2;
    unk4   = 2;
    unk2   = 1;
    subId  = 0;
  }
};