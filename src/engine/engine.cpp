/*

TCODMaze::Engine

*/

#include "engine.hpp"

#include "maze.hpp"
#include "scene.hpp"
#include "vector2i.hpp"

namespace TCODMaze {

int Engine::getMazeSize() const { return this->mazeSize * 2 + 1; }
void Engine::set_max_maze_size(int i) { this->maxMazeSize = i; }

GameState Engine::update() {
  if (this->state == RUN) {
    if (this->active_player->position ==
        vector2i(this->getMazeSize() - 1, this->getMazeSize() - 2)) {
      if (this->getMazeSize() < this->maxMazeSize) {
        ++(this->mazeSize);
        this->state = SETUP;
      } else {
        this->state = WIN;
      }
    }

    for (auto actr : this->active_scene->actors) actr->execute_action();
  }

  if (this->state == SETUP) {
    maze maze_gen(this->mazeSize, this->mazeSize);
    this->active_scene = maze_gen.get_scene();
    this->active_player = this->active_scene->create_actor(vector2i(0, 1));
    this->state = RUN;
  }

  return state;
}

}  // namespace TCODMaze
