cmake_minimum_required (VERSION 2.6)

project(mcpelauncher-core LANGUAGES CXX)

add_library(mcpelauncher-core include/mcpelauncher/app_platform.h include/mcpelauncher/hook.h include/mcpelauncher/mod_loader.h include/mcpelauncher/hybris_utils.h include/mcpelauncher/patch_utils.h include/mcpelauncher/crash_handler.h include/mcpelauncher/minecraft_utils.h src/app_platform.cpp src/hook.cpp src/mod_loader.cpp src/hybris_utils.cpp src/hybris_android_log_hook.cpp src/crash_handler.cpp src/patch_utils.cpp src/minecraft_utils.cpp include/mcpelauncher/minecraft_version.h)
target_include_directories(mcpelauncher-core PUBLIC include/)
target_link_libraries(mcpelauncher-core mcpelauncher-common logger hybris minecraft-symbols minecraft-imported-symbols ${CMAKE_DL_LIBS})

if(APPLE)
    target_link_libraries(mcpelauncher-core osx-elf-header)
endif()

if (IS_ARMHF_BUILD)
    target_compile_definitions(mcpelauncher-core PRIVATE USE_BIONIC_LIBC)
endif()