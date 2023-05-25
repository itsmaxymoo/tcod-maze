/*

TCODMaze::Engine

*/

#include "engine.hpp"

#include "maze.hpp"

namespace TCODMaze {

int Engine::getMazeSize() const { return this->mazeSize * 2 + 1; }

GameState Engine::update() {
  if (this->state == PRE) {
    this->maze = Maze(this->mazeSize, this->mazeSize);
    this->player = Vector2i(0, 1);
    ++(this->mazeSize);
    this->state = MAIN;
  }

  return state;
}

}  // namespace TCODMaze
