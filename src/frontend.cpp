/*

Frontend Implementation

*/

#include "frontend.hpp"

#include <SDL.h>

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <libtcod.hpp>

namespace TCODMaze {

int FrontEnd::run(Engine &engine) { return 1; }

// --- TCOD Frontend

// Return the data directory.
auto get_data_dir() -> std::filesystem::path {
  static auto root_directory =
      std::filesystem::path{"."};  // Begin at the working directory.
  while (!std::filesystem::exists(root_directory / "data")) {
    // If the current working directory is missing the data dir then it will
    // assume it exists in any parent directory.
    root_directory /= "..";
    if (!std::filesystem::exists(root_directory)) {
      throw std::runtime_error("Could not find the data directory.");
    }
  }
  return root_directory / "data";
};

static tcod::Console g_console;  // The global console object.
static tcod::Context g_context;  // The global libtcod context.

int TCODAsciiFrontEnd::run(Engine &engine) {
  // Setup TCOD
  auto params = TCOD_ContextParams{};
  params.tcod_version = TCOD_COMPILEDVERSION;
  params.renderer_type = TCOD_RENDERER_SDL2;
  params.vsync = 1;
  params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
  params.window_title = "TCOD Maze";

  auto tileset = tcod::load_tilesheet(get_data_dir() / "dejavu16x16_gs_tc.png",
                                      {32, 8}, tcod::CHARMAP_TCOD);
  params.tileset = tileset.get();

  g_console = tcod::Console{80, 40};
  params.console = g_console.get();

  g_context = tcod::Context(params);

  while (true) {
    // Rendering.
    g_console.clear();
    tcod::print(g_console, {0, 0}, "Hello World", TCOD_ColorRGB{255, 255, 255}, std::nullopt);
    g_context.present(g_console);

    // Handle input.
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          std::exit(EXIT_SUCCESS);
          break;
      }
    }
  }

  return 0;
}

}  // namespace TCODMaze