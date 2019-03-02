PROJECT(sqlite3)
cmake_minimum_required(VERSION 3.3)

include_directories(${CMAKE_SOURCE_DIR}/src)
add_library(sqlite3 STATIC src/sqlite3.c src/sqlite3.h src/sqlite3ext.h)

target_compile_definitions(sqlite3 PRIVATE -DSQLITE_ENABLE_RTREE)
target_compile_definitions(sqlite3 PRIVATE -DSQLITE_ENABLE_FTS4)
target_compile_definitions(sqlite3 PRIVATE -DSQLITE_ENABLE_FTS5)
target_compile_definitions(sqlite3 PRIVATE -DSQLITE_ENABLE_JSON1)
target_compile_definitions(sqlite3 PRIVATE -DSQLITE_ENABLE_RBU)
target_compile_definitions(sqlite3 PRIVATE -DSQLITE_ENABLE_STAT4)
target_compile_definitions(sqlite3 PRIVATE -DSQLITE_DEFAULT_FOREIGN_KEYS=1)
target_compile_definitions(sqlite3 PRIVATE -DSQLITE_DEFAULT_SYNCHRONOUS=0)
target_compile_definitions(sqlite3 PRIVATE -DSQLITE_THREADSAFE=0)

install(FILES src/sqlite3.h src/sqlite3ext.h DESTINATION include)
install(TARGETS sqlite3 LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
