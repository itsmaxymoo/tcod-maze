/*

TCODMaze::Engine

*/

#include "engine.hpp"

#include "maze.hpp"

namespace TCODMaze {

int Engine::getMazeSize() const { return this->mazeSize * 2 + 1; }

GameState Engine::update() {
  if (this->state == SETUP) {
    maze maze_gen(this->mazeSize, this->mazeSize);
    this->active_scene = maze_gen.get_scene();
    this->player = vector2i(0, 1);
    ++(this->mazeSize);
    this->state = LOOP;
  }

  return state;
}

}  // namespace TCODMaze
