/*

TCODMaze::scene

*/

#include "scene.hpp"

namespace TCODMaze {

tile_t scene::get_cell(Vector2i pos) {
  if (this->static_map.find(pos) == this->static_map.end()) {
    return this->default_tile;
  } else {
    return static_map[pos];
  }
}

std::shared_ptr<actor> scene::create_actor(Vector2i pos) {
  auto new_actor = std::shared_ptr<actor>(new actor(this, pos));
  actors->push_back(new_actor);
  return new_actor;
}

}  // namespace TCODMaze
