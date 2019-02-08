#pragma once

#include "Packet.h"
#include "std/string.h"
#include <vector>

enum struct TextPacketType : unsigned char {

};

struct TextPacket : Packet {
  TextPacketType type;           // 16
  mcpe::string name, message;    // 20, 24
  std::vector<mcpe::string> vec; // 32
  bool translated;               // 40
  mcpe::string xuid, unk48;      // 44, 48

  /// @symbol _ZN10TextPacketC2E14TextPacketTypeRKSsS2_RKSt6vectorISsSaISsEEbS2_S2_
  TextPacket(TextPacketType, mcpe::string const &, mcpe::string const &, std::vector<mcpe::string> const &, bool, mcpe::string const &,
             mcpe::string const &);

  /// @symbol _ZN10TextPacket9createRawERKSs
  static TextPacket createRaw(mcpe::string const &);
  /// @symbol _ZN10TextPacket18createJukeboxPopupERKSs
  static TextPacket createJukeboxPopup(mcpe::string const &);
  /// @symbol _ZN10TextPacket19createSystemMessageERKSs
  static TextPacket createSystemMessage(mcpe::string const &);
  /// @symbol _ZN10TextPacket10createChatERKSsS1_S1_S1_
  static TextPacket createChat(mcpe::string const &, mcpe::string const &, mcpe::string const &, mcpe::string const &);
  /// @symbol _ZN10TextPacket20createTranslatedChatERKSsS1_S1_S1_
  static TextPacket createTranslatedChat(mcpe::string const &, mcpe::string const &, mcpe::string const &, mcpe::string const &);
  /// @symbol _ZN10TextPacket28createTranslatedAnnouncementERKSsS1_S1_S1_
  static TextPacket createTranslatedAnnouncement(mcpe::string const &, mcpe::string const &, mcpe::string const &, mcpe::string const &);
  /// @symbol _ZN10TextPacket13createWhisperERKSsS1_S1_S1_
  static TextPacket createWhisper(mcpe::string const &, mcpe::string const &, mcpe::string const &, mcpe::string const &);
  /// @symbol _ZN10TextPacket16createTranslatedERKSsRKSt6vectorISsSaISsEE
  static TextPacket createTranslated(mcpe::string const &, std::vector<mcpe::string> const &);
};