cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(arboles)

enable_testing()

add_subdirectory(test)

add_library(${PROJECT_NAME} src/arboles.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

