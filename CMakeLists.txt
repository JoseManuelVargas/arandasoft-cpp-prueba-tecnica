cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

if (WIN32)
	if (NOT DEFINED VCPKG_ROOT)
		set(VCPKG_ROOT "c:/dev/vcpkg")
	endif()
	set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake	CACHE STRING "Vcpkg toolchain file")
endif()

project(prueba-tecnica)

enable_testing()
find_package(cpprestsdk REQUIRED)
# target_link_libraries(${PROJECT_NAME} cpprestsdk::cpprest)

add_subdirectory(googletest)
add_subdirectory(soci)
# add_subdirectory(json)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/soci/include)

add_subdirectory(arboles)
add_subdirectory(basedatos)
add_subdirectory(servicio)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} servicio)

