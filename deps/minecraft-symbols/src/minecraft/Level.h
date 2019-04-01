#pragma once

#include "EventResult.h"
#include "Player.h"
#include "UUID.h"
#include "std/function.h"
#include "std/string.h"
#include <list>
#include <memory>
#include <vector>

class ServerLevelEventListener {};

class ServerLevelEventCoordinator {
  std::vector<ServerLevelEventListener *> listeners;
  std::vector<mcpe::function<EventResult(ServerLevelEventListener *)>> handlers;
  char filler[36 - 28];
};

class Player;
class Level;
class LevelListener;
class Block;
class ActorBlockSyncMessage;
class BlockActor;
enum class ParticleType;
class HashedString;
class MolangVariableMap;
class LevelChunk;
class LevelEvent {};
class LevelSoundEvent {};
class ScreenshotOptions;
namespace cg {
class ImageBuffer;
}

class BlockSourceListener {
public:
  virtual ~BlockSourceListener();
  virtual void onSourceCreated(BlockSource &);
  virtual void onSourceDestroyed(BlockSource &);
  /// @symbol _ZN19BlockSourceListener13onAreaChangedER11BlockSourceRK8BlockPosS4_
  virtual void onAreaChanged(BlockSource &, BlockPos const &, BlockPos const &);
  /// @symbol _ZN19BlockSourceListener14onBlockChangedER11BlockSourceRK8BlockPosjRK5BlockS7_iPK21ActorBlockSyncMessage
  virtual void onBlockChanged(BlockSource &, BlockPos const &, uint, Block const &, Block const &, int, ActorBlockSyncMessage const *);
  virtual void onBrightnessChanged(BlockSource &, BlockPos const &);
  virtual void onBlockEntityChanged(BlockSource &, BlockActor &);
  virtual void onBlockEntityAboutToBeRemoved(BlockSource &, std::shared_ptr<BlockActor>){};
  virtual void onEntityChanged(BlockSource &, Actor &);
  virtual void onBlockEvent(BlockSource &, int, int, int, int, int);
};

class LevelListener : BlockSourceListener {
public:
  virtual void allChanged();
  /// @symbol _ZN13LevelListener11addParticleE12ParticleTypeRK4Vec3S3_iPK11CompoundTagb
  virtual void addParticle(ParticleType, Vec3 const &, Vec3 const &, int, CompoundTag const *, bool);
  /// @symbol _ZN13LevelListener17addParticleEffectERK12HashedStringRK4Vec3RK17MolangVariableMap
  virtual void addParticleEffect(HashedString const &, Vec3 const &, MolangVariableMap const &);
  /// @symbol _ZN13LevelListener17addParticleEffectERK12HashedStringRK5ActorS2_RK4Vec3RK17MolangVariableMap
  virtual void addParticleEffect(HashedString const &, Actor const &, HashedString const &, Vec3 const &, MolangVariableMap const &);
  virtual void addTerrainParticleEffect(BlockPos const &, Block const &, Vec3 const &, float, float, float);
  virtual void playMusic(mcpe::string const &, Vec3 const &, float, float);
  virtual void playStreamingMusic(mcpe::string const &, int, int, int);
  virtual void onEntityAdded(Actor &);
  virtual void onEntityRemoved(Actor &);
  virtual void onNewChunk(BlockSource &, LevelChunk &);
  virtual void onNewChunkFor(Player &, LevelChunk &);
  virtual void onChunkLoaded(LevelChunk &);
  virtual void onChunkUnloaded(LevelChunk &);
  virtual void onLevelDestruction(mcpe::string const &);
  virtual void levelEvent(LevelEvent, Vec3 const &, int);
  virtual void levelSoundEvent(LevelSoundEvent, Vec3 const &, int, ActorDefinitionIdentifier const &, bool, bool);
  virtual void levelSoundEvent(mcpe::string const &, Vec3 const &, float, float);
  virtual void stopSoundEvent(mcpe::string const &);
  virtual void stopAllSounds();
  /// @symbol _ZN13LevelListener11takePictureERN2cg11ImageBufferEP5ActorS4_R17ScreenshotOptions
  virtual void takePicture(cg::ImageBuffer &, Actor *, Actor *, ScreenshotOptions &);
  virtual void playerListChanged();
};

class Level {

public:
  static unsigned int createRandomSeed();

  ServerLevelEventCoordinator *&_getServerLevelEventCoordinator();

  void _setServerLevelEventCoordinator(std::unique_ptr<ServerLevelEventCoordinator, std::default_delete<ServerLevelEventCoordinator>> &&);

  void suspendPlayer(Player &);
  void resumePlayer(Player &);

  BlockPos const &getDefaultSpawn() const;
  void setDefaultSpawn(BlockPos const &);
  Player *getPlayer(const std::string &name) const;

  void addListener(LevelListener &);
  void removeListener(LevelListener &);

  std::list<Player *> &getPlayerList();
};