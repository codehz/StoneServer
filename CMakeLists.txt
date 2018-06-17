cmake_minimum_required (VERSION 3.1)

project(hybris LANGUAGES C)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(HYBRIS_SOURCES src/cache.c src/dlfcn.c src/hooks.c src/hooks_shm.c src/logging.c src/properties.c src/ctype.c src/sysconf.c src/jb/dlfcn.c src/jb/linker.c src/jb/linker_environ.c src/jb/linker_format.c src/jb/rt.c src/hooks_pthread.c src/hooks_dirent.c src/hooks_io.c src/hooks_net.c src/hooks_list.c)
if(APPLE)
    set(HYBRIS_SOURCES ${HYBRIS_SOURCES} src/hooks_net_darwin.c src/hooks_darwin_pthread_once.cpp)
else()
    set(HYBRIS_SOURCES ${HYBRIS_SOURCES} src/strlcpy.c src/hooks_list.c src/hooks_list.h)
endif(APPLE)

add_library(hybris ${HYBRIS_SOURCES})
target_include_directories(hybris PUBLIC include/)
target_compile_definitions(hybris PRIVATE ANDROID_X86_LINKER _GNU_SOURCE LINKER_TEXT_BASE=0xB0000100 LINKER_AREA_SIZE=0x01000000 LINKER_DEBUG=1)
target_link_libraries(hybris Threads::Threads)

if(APPLE)
    target_link_libraries(hybris epoll-shim osx-elf-header)
else()
    target_link_libraries(hybris rt)
endif()
