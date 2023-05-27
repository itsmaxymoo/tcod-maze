/*

TCOD Frontend Implementation

*/

#include "tcod_frontend.hpp"

#include <SDL.h>

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <libtcod.hpp>

#include "engine/vector2i.hpp"

#define WINDOW_SIZE 41

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

int TCODAsciiFrontEnd::run(TCODMaze::Engine *engine) {
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

  g_console = tcod::Console{WINDOW_SIZE, WINDOW_SIZE};
  params.console = g_console.get();

  g_context = tcod::Context(params);

  while (true) {
    if (engine->update() == TCODMaze::GameState::SETUP) continue;

    // --- Rendering.
    g_console.clear();

    // Calculate centering offset
    const int OFFSET = WINDOW_SIZE / 2 - engine->getMazeSize() / 2 + 1;

    // Render map
    for (int i = 0; i < engine->getMazeSize(); ++i) {
      for (int j = 0; j < engine->getMazeSize(); ++j) {
        auto this_tile = engine->active_scene->get_cell(TCODMaze::vector2i(i, j));
        tcod::print(
            g_console, {(i + OFFSET), (j + OFFSET)},
            std::string(1, (char)(this_tile.ascii)),
            TCOD_ColorRGB{this_tile.ascii_color.r, this_tile.ascii_color.g,
                          this_tile.ascii_color.b},
            std::nullopt);
      }
    }

    // Render player
    tcod::print(g_console,
                {(engine->player.x + OFFSET), (engine->player.y + OFFSET)}, "@",
                TCOD_ColorRGB{255, 255, 255}, std::nullopt);

    // flush
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