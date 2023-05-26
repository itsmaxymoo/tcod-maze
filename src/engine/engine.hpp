/*

This class defines the main game loop.

*/

#ifndef TCOD_MAZE_ENGINE
#define TCOD_MAZE_ENGINE

#include <memory>

#include "actor.hpp"
#include "scene.hpp"

namespace TCODMaze {

enum GameState { PRE, MAIN, LOSE };

class Engine {
 private:
  GameState state = PRE;
  int mazeSize = 3;

 public:
  maze gen_maze;
  Vector2i player;

  int getMazeSize() const;

  GameState update();
};
}  // namespace TCODMaze

#endif