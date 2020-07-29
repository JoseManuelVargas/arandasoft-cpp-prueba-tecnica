cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

set(This servicios-test)

add_executable(${This} serviciostest.cpp)

target_link_libraries(${This} gtest_main servicio basedatos arboles)

add_test(NAME ${This} COMMAND ${This})

add_custom_command(TARGET ${This} COMMENT "Ejecutando prueba de los servicios REST" POST_BUILD COMMAND ${This})

