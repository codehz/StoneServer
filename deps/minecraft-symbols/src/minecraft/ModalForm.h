#pragma once

#include "Packet.h"
#include "std/string.h"

struct ModalFormRequestPacket : Packet {
  /// @symbol _ZTV22ModalFormRequestPacket
  static void *myVtable;
  unsigned request_id;
  mcpe::string content;

  ModalFormRequestPacket(unsigned request_id, mcpe::string content)
      : request_id(request_id)
      , content(content) {
    vtable = (void **)myVtable + 2;
    unk4   = 2;
    unk2   = 1;
    subId  = 0;
  }
};

struct ModalFormResponsePacket : Packet {
  /// @symbol _ZTV23ModalFormResponsePacket
  static void *myVtable;
  unsigned request_id;
  mcpe::string content;

  ModalFormResponsePacket(unsigned request_id, mcpe::string content)
      : request_id(request_id)
      , content(content) {
    vtable = (void **)myVtable + 2;
    unk4   = 2;
    unk2   = 1;
    subId  = 0;
  }
};