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

std::shared_ptr<Actor> scene::create_actor(Vector2i pos) {
  auto actor = std::shared_ptr<Actor>(new Actor(this, pos));
  actors->push_back(actor);
  return actor;
}

}  // namespace TCODMaze
