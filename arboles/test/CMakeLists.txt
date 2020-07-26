cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

set(This arboles-test)

add_executable(${This} arbolestest.cpp)

target_link_libraries(${This} gtest_main arboles)

add_test(NAME ${This} COMMAND ${This})

add_custom_command(TARGET ${This} COMMENT "Ejecutando test de arboles y nodos" POST_BUILD COMMAND ${This})

