/*

This class defines the main game loop.

*/

#ifndef TCOD_MAZE_ENGINE
#define TCOD_MAZE_ENGINE

#include <memory>

#include "actor.hpp"
#include "scene.hpp"

namespace TCODMaze {

enum GameState { SETUP, LOOP, END };

class Engine {
 private:
  GameState state = SETUP;
  int mazeSize = 3;

 public:
  std::shared_ptr<scene> active_scene;
  vector2i player;

  int getMazeSize() const;

  GameState update();
};
}  // namespace TCODMaze

#endif