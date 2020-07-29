cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(basedatos)

enable_testing()

add_subdirectory(test)

add_library(${PROJECT_NAME} src/conexionbd.cpp src/mapeadorarbolbinario.cpp src/fechas.cpp)


target_link_libraries(${PROJECT_NAME} soci_core soci_sqlite3 arboles)

target_include_directories(${PROJECT_NAME} PUBLIC include)

