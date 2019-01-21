cmake_minimum_required (VERSION 2.6)

project(dbus-api LANGUAGES CXX)

add_library(dbus-api INTERFACE)
file(GLOB src "include/dbus-api/*")
target_sources(dbus-api INTERFACE ${src})
target_compile_definitions(dbus-api INTERFACE SIMPPL_HAVE_INTROSPECTION=true)
target_link_libraries(dbus-api INTERFACE simppl)
target_include_directories(dbus-api INTERFACE "include")

macro(dbus_api_add_multi_call name)
  add_library(dbus-api-${name} src/${name}.cpp src/multi-call.h)
  set_property(TARGET dbus-api-${name} PROPERTY CXX_STANDARD 17)
  target_link_libraries(dbus-api-${name} PRIVATE dbus-api)
  list(APPEND dbus_api_commands dbus-api-${name})
endmacro(dbus_api_add_multi_call)

dbus_api_add_multi_call(logger)
dbus_api_add_multi_call(chat)
dbus_api_add_multi_call(chat-send)
dbus_api_add_multi_call(chat-broadcast)
dbus_api_add_multi_call(command)
dbus_api_add_multi_call(userlist)
dbus_api_add_multi_call(blacklist)

add_executable(dbus-api-bin src/main.cpp src/multi-call.h src/json.cpp include/json.h)
target_link_libraries(dbus-api-bin PRIVATE -Wl,--whole-archive ${dbus_api_commands} -Wl,--no-whole-archive dbus-api stdc++fs)
set_property(TARGET dbus-api-bin PROPERTY CXX_STANDARD 20)

install(FILES ${src} DESTINATION include/dbus-api)
install(TARGETS dbus-api-bin RUNTIME DESTINATION bin)
foreach(target ${dbus_api_commands})
  install(CODE "execute_process( \
    COMMAND ln -sf dbus-api-bin ${target} \
    WORKING_DIRECTORY \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin
  )")
  install(CODE "message(\"-- Created symlink: dbus-api-bin -> \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/${target}\")")
endforeach(target)
