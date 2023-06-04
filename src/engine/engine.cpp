/*

TCODMaze::Engine

*/

#include "engine.hpp"

#include <chrono>

#include "maze.hpp"
#include "scene.hpp"
#include "vector2i.hpp"

namespace TCODMaze {

int Engine::getMazeSize() const { return this->mazeSize * 2 + 1; }

void Engine::set_max_maze_size(int i) { this->maxMazeSize = i; }

int Engine::get_max_time() const { return this->mazeSize; }

float Engine::get_remaining_time() const {
  auto current_time = std::chrono::steady_clock::now();

  return this->get_max_time() -
         ((float)(std::chrono::duration_cast<std::chrono::milliseconds>(
                      current_time - this->level_start_time)
                      .count())) /
             1000.f;
}

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

    if (this->get_remaining_time() <= 0) this->state = LOSE;
  }

  if (this->state == SETUP) {
    maze maze_gen(this->mazeSize, this->mazeSize);
    this->active_scene = maze_gen.get_scene();
    this->active_player = this->active_scene->create_actor(vector2i(0, 1));
    this->level_start_time = std::chrono::steady_clock::now();
    this->state = RUN;
  }

  return state;
}

}  // namespace TCODMaze
