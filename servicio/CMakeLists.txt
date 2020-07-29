cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(servicio)

enable_testing()

# add_subdirectory(test)

add_library(${PROJECT_NAME} src/clienterest.cpp src/controladorrest.cpp src/servicioarboles.cpp src/servidorrest.cpp src/utilidadesservicio.cpp)


target_link_libraries(${PROJECT_NAME} cpprestsdk::cpprest basedatos)

target_include_directories(${PROJECT_NAME} PUBLIC include)

