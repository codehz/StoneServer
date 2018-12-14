cmake_minimum_required(VERSION 3.7)

project(stone LANGUAGES CXX)

add_executable(stone
  "src/main.cpp"

  "src/server_properties.h"
  "src/server_minecraft_app.h"
  "src/stub_key_provider.h"
  "src/dependency.cpp"
  "src/services.h"
  "src/operators.h"
  "src/patched.h"
  "src/patched.cpp"
  "src/patched/ServerLevelEventCoordinator.cpp"
  "src/patched/ServerInstanceEventCoordinator.cpp"
  "src/patched/TextPacket.cpp"
  "src/patched/Education.cpp"
  "src/patched/Player.h"
)

target_compile_definitions(stone PRIVATE SIMPPL_HAVE_INTROSPECTION=true)
set_property(TARGET stone PROPERTY CXX_STANDARD 17)
target_compile_options(stone PRIVATE -Wall -Wno-reorder -Wno-class-memaccess)
add_dependencies(stone simppl)
target_link_libraries(stone logger mcpelauncher-core properties-parser utils uintl simppl interface dbus-api)
if (${USE_COTIRE})
  cotire(stone)
endif()

install(TARGETS stone RUNTIME DESTINATION bin)
