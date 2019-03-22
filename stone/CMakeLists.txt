cmake_minimum_required(VERSION 3.7)

project(stone LANGUAGES CXX)

add_executable(stone
  "src/main.cpp"

  "src/dumper.h"
  "src/dumper.cpp"
  "src/server_properties.h"
  "src/server_minecraft_app.h"
  "src/v8_utils.hpp"
  "src/v8_platform.h"
  "src/v8_platform.cpp"
  "src/stub_key_provider.h"
  "src/dependency.cpp"
  "src/services.h"
  "src/operators.h"
  "src/custom_command.hpp"
  "src/custom_command.h"
  "src/whitelist_mgr.hpp"
  "src/patched.h"
  "src/patched.cpp"
  "src/patched/ServerLevelEventCoordinator.cpp"
  "src/patched/PlayerCommandOrigin.cpp"
  "src/patched/ScriptEventCoordinator.cpp"
  "src/patched/FlatWorldGeneratorOptions.cpp"
  "src/patched/TextPacket.cpp"
  "src/patched/Ability.cpp"
  "src/patched/Common.cpp"
  "src/patched/ServerMetrics.cpp"
  "src/patched/SayCommand.cpp"
  "src/patched/Education.cpp"
  "src/patched/Encryption.cpp"
  "src/patched/ScriptEngine.cpp"
  "src/patched/v8.cpp"
  "src/patched/Level.cpp"
  "src/patched/FeatureToggles.cpp"
  "src/patched/HardcodedOffsets.h"
  "src/patched/ScriptInterface.h"
  "src/patched/ServerNetworkHandler.cpp"
  "src/patched/ServerCommandOrigin.cpp"
  "src/patched/ModalForm.cpp"
  "src/ExtAPI/common.h"
  "src/ExtAPI/common.cpp"
  "src/ExtAPI/checks.cpp"
  "src/ExtAPI/log.cpp"
  "src/ExtAPI/broadcastMessage.cpp"
  "src/ExtAPI/invokeCommand.cpp"
  "src/ExtAPI/invokeConsoleCommand.cpp"
  "src/ExtAPI/invokePrivilegedCommand.cpp"
  "src/ExtAPI/registerCommand.cpp"
  "src/ExtAPI/registerSoftEnum.cpp"
  "src/ExtAPI/updateSoftEnum.cpp"
  "src/ExtAPI/transferPlayer.cpp"
  "src/ExtAPI/changeDimension.cpp"
  "src/ExtAPI/broadcastExternalEvent.cpp"
  "src/ExtAPI/openModalForm.cpp"
  "src/ExtAPI/muteChat.cpp"
  "src/ExtAPI/actorInfo.cpp"
  "src/GlobalAPI/common.h"
  "src/GlobalAPI/common.cpp"
  "src/GlobalAPI/SQLite3.cpp"
  "src/GlobalAPI/checkApiLevel.cpp"
)

target_compile_definitions(stone PRIVATE SIMPPL_HAVE_INTROSPECTION=true)
set_property(TARGET stone PROPERTY CXX_STANDARD 17)
target_compile_options(stone PRIVATE -Wall -Wno-reorder -Wno-class-memaccess)
target_link_libraries(stone logger mcpelauncher-core properties-parser utils interface stone-api sqlite3 build_version)
if (${USE_COTIRE})
  cotire(stone)
endif()

install(TARGETS stone RUNTIME DESTINATION bin)
