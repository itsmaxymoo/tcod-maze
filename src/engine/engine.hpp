/*

This class defines the main game loop.

*/

#ifndef TCOD_MAZE_ENGINE
#define TCOD_MAZE_ENGINE

#include <memory>

#include "actor.hpp"
#include "scene.hpp"

namespace TCODMaze {

enum GameState { SETUP, RUN, WIN, LOSE };

class Engine {
 private:
  GameState state = SETUP;
  int mazeSize = 3;
  int maxMazeSize = 10;

 public:
  std::shared_ptr<scene> active_scene;
  std::shared_ptr<actor> active_player;

  int getMazeSize() const;
  void set_max_maze_size(int);

  GameState update();
};
}  // namespace TCODMaze

#endif