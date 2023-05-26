cmake_minimum_required(VERSION 3.15)

# Vcpkg

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	set(CMAKE_TOOLCHAIN_FILE
		"${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
		CACHE STRING "Vcpkg toolchain file")
endif()

# --------------------------------------------

# Project Info
project(tcod-maze VERSION 0.0.0 LANGUAGES CXX)

# Project files
add_executable(${PROJECT_NAME} src/main.cpp src/engine/maze.cpp src/engine/vector2i.cpp src/engine/actor.cpp src/engine/action.cpp src/engine/scene.cpp src/engine/engine.cpp src/engine/frontend.cpp src/tcod_frontend.cpp src/engine/color.hpp src/engine/tile.hpp)

# Dependencies
find_package(SDL2 CONFIG REQUIRED)
find_package(libtcod CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main libtcod::libtcod)

# Build settings
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
if(NOT MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
endif()