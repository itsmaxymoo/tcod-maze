cmake_minimum_required(VERSION 3.15)

# Vcpkg

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	set(CMAKE_TOOLCHAIN_FILE
		"${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
		CACHE STRING "Vcpkg toolchain file")
endif()

# --------------------------------------------

project(tcod-maze VERSION 0.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(libtcod CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE libtcod::libtcod)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")