cmake_minimum_required (VERSION 2.6)

project(dbus-api LANGUAGES CXX)

add_library(dbus-api INTERFACE)
file(GLOB src "include/dbus-api/*")
target_sources(dbus-api INTERFACE ${src})
target_compile_definitions(dbus-api INTERFACE SIMPPL_HAVE_INTROSPECTION=true)
target_link_libraries(dbus-api INTERFACE simppl)
target_include_directories(dbus-api INTERFACE "include")

add_executable(dbus-api-logger src/logger.cpp)
target_link_libraries(dbus-api-logger PRIVATE dbus-api)

add_executable(dbus-api-chat src/chat.cpp)
target_link_libraries(dbus-api-chat PRIVATE dbus-api)

add_executable(dbus-api-chat-send src/chat-send.cpp)
target_link_libraries(dbus-api-chat-send PRIVATE dbus-api)

add_executable(dbus-api-userlist src/userlist.cpp)
target_link_libraries(dbus-api-userlist PRIVATE dbus-api)

install(FILES ${src} DESTINATION include/dbus-api)
install(TARGETS dbus-api-logger dbus-api-chat dbus-api-chat-send dbus-api-userlist RUNTIME DESTINATION bin)
