/*

TCOD Frontend Implementation

*/

#include "tcod_frontend.hpp"

#include <SDL.h>

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <libtcod.hpp>

#include "actions.hpp"
#include "engine/vector2i.hpp"

#define WINDOW_SIZE 41
#define MAX_MAZE_SIZE WINDOW_SIZE - 30

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
  params.sdl_window_flags = 0b0;
  params.window_title = "TCOD Maze";

  auto tileset = tcod::load_tilesheet(get_data_dir() / "dejavu16x16_gs_tc.png",
                                      {32, 8}, tcod::CHARMAP_TCOD);
  params.tileset = tileset.get();

  g_console = tcod::Console{WINDOW_SIZE, WINDOW_SIZE};
  params.console = g_console.get();

  g_context = tcod::Context(params);

  engine->set_max_maze_size(MAX_MAZE_SIZE);

  // frame loop
  while (true) {
    auto state = engine->update();

    if (state == TCODMaze::GameState::SETUP) continue;

    // --- Rendering.
    g_console.clear();

    // Calculate centering offset
    const int OFFSET = WINDOW_SIZE / 2 - engine->getMazeSize() / 2;

    // Render map
    for (int i = 0; i < engine->getMazeSize(); ++i) {
      for (int j = 0; j < engine->getMazeSize(); ++j) {
        auto this_tile =
            engine->active_scene->get_cell(TCODMaze::vector2i(i, j));
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
                {(engine->active_player->position.x + OFFSET),
                 (engine->active_player->position.y + OFFSET)},
                "@", TCOD_ColorRGB{255, 255, 255}, std::nullopt);

    // state specific display
    switch (state) {
      case TCODMaze::GameState::RUN:
        tcod::print(
            g_console, {0, 0},
            "Remaining time: " + std::to_string(engine->get_remaining_time()),
            (TCOD_ColorRGB){0xFF, 0xFF, 0xFF}, std::nullopt);
        break;
      case TCODMaze::GameState::WIN:
        tcod::print(g_console, {0, WINDOW_SIZE - 1},
                    "Congratulations, you made it to the end!",
                    (TCOD_ColorRGB){0x30, 0xFF, 0x30}, std::nullopt);
        break;
      case TCODMaze::GameState::LOSE:
        tcod::print(g_console, {0, WINDOW_SIZE - 1}, "Out of time. You lose!",
                    (TCOD_ColorRGB){0xFF, 0x30, 0x30}, std::nullopt);
      default:
        break;
    }

    // flush
    g_context.present(g_console);

    // Handle input.
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        // Window quit
        case SDL_QUIT:
          std::exit(EXIT_SUCCESS);
          break;

        // Regular keyboard keypresses
        case SDL_KEYDOWN:
          auto move_dir = std::make_shared<move_action>();
          switch (event.key.keysym.sym) {
            // move
            case SDLK_UP:
              move_dir->direction = TCODMaze::vector2i(0, -1);
              break;
            case SDLK_DOWN:
              move_dir->direction = TCODMaze::vector2i(0, 1);
              break;
            case SDLK_LEFT:
              move_dir->direction = TCODMaze::vector2i(-1, 0);
              break;
            case SDLK_RIGHT:
              move_dir->direction = TCODMaze::vector2i(1, 0);
              break;
          }
          // Execute move
          engine->active_player->set_next_action(move_dir);
          break;
      }
    }
  }

  return 0;
}