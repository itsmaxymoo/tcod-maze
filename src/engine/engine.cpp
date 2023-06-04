/*

TCODMaze::Engine

*/

#include "engine.hpp"

#include "maze.hpp"
#include "scene.hpp"
#include "vector2i.hpp"

namespace TCODMaze {

int Engine::getMazeSize() const { return this->mazeSize * 2 + 1; }

GameState Engine::update() {
  if (this->state == SETUP) {
    maze maze_gen(this->mazeSize, this->mazeSize);
    this->active_scene = maze_gen.get_scene();
    this->active_player = this->active_scene->create_actor(vector2i(0, 1));
    ++(this->mazeSize);
    this->state = LOOP;
  }

  if (this->state == LOOP) {
    for (auto actr : this->active_scene->actors) actr->execute_action();
  }

  return state;
}

}  // namespace TCODMaze
