cmake_minimum_required(VERSION 3.7)

project(stone LANGUAGES CXX)

add_executable(stone
  "src/main.cpp"

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
  "src/patched/DedicatedServerCommandOrigin.cpp"
  "src/patched/PlayerCommandOrigin.cpp"
  "src/patched/ScriptEventCoordinator.cpp"
  "src/patched/TextPacket.cpp"
  "src/patched/SayCommand.cpp"
  "src/patched/Education.cpp"
  "src/patched/v8.cpp"
  "src/patched/FeatureToggles.cpp"
  "src/patched/Player.h"
  "src/patched/ServerNetworkHandler.cpp"
  "src/ExtAPI/common.h"
  "src/ExtAPI/common.cpp"
  "src/ExtAPI/broadcastMessage.cpp"
  "src/ExtAPI/currentCommandOrigin.cpp"
  "src/ExtAPI/invokeCommand.cpp"
  "src/ExtAPI/invokeConsoleCommand.cpp"
  "src/ExtAPI/invokePrivilegedCommand.cpp"
  "src/ExtAPI/registerCommand.cpp"
  "src/ExtAPI/transferPlayer.cpp"
)

target_compile_definitions(stone PRIVATE SIMPPL_HAVE_INTROSPECTION=true)
set_property(TARGET stone PROPERTY CXX_STANDARD 17)
target_compile_options(stone PRIVATE -Wall -Wno-reorder -Wno-class-memaccess)
target_link_libraries(stone logger mcpelauncher-core properties-parser utils uintl interface)
if (${USE_COTIRE})
  cotire(stone)
endif()

install(TARGETS stone RUNTIME DESTINATION bin)
