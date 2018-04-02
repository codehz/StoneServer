cmake_minimum_required (VERSION 2.6)

project(mcpelauncher-core LANGUAGES CXX)

add_library(mcpelauncher-core include/mcpelauncher/appplatform.h include/mcpelauncher/hook.h include/mcpelauncher/modloader.h include/mcpelauncher/hybris_utils.h include/mcpelauncher/patch_utils.h include/mcpelauncher/crash_handler.h include/mcpelauncher/minecraft_utils.h src/appplatform.cpp src/hook.cpp src/modloader.cpp src/hybris_utils.cpp src/hybris_android_log_hook.cpp src/crash_handler.cpp src/patch_utils.cpp src/minecraft_utils.cpp)
target_include_directories(mcpelauncher-core PUBLIC include/)
target_link_libraries(mcpelauncher-core mcpelauncher-common logger hybris minecraft-symbols)
target_compile_definitions(mcpelauncher-core PRIVATE SERVER) # temporary workaround to make it compile