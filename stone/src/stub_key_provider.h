#pragma once

#include <minecraft/ResourcePack.h>
#include <minecraft/UUID.h>
#include <minecraft/std/string.h>
#include <unordered_map>

class StubKeyProvider : public IContentKeyProvider {

public:
  virtual ~StubKeyProvider() {}
  virtual mcpe::string getContentKey(mce::UUID const &) { return mcpe::string(); }
  virtual mcpe::string getAlternativeContentKey(mce::UUID const &) { return mcpe::string(); }
  virtual void setTempContentKeys(std::unordered_map<std::string, std::string> const &) {}
  virtual void clearTempContentKeys() {}
};