/*

TCODMaze::scene

*/

#include "scene.hpp"

namespace TCODMaze {

tile_t scene::get_cell(vector2i pos) {
  if (this->static_map.find(pos) == this->static_map.end()) {
    return this->default_tile;
  } else {
    return static_map[pos];
  }
}

void scene::set_cell(vector2i pos, tile_t tile) {
  this->static_map[pos] == tile;
}

std::shared_ptr<actor> scene::create_actor(vector2i pos) {
  auto new_actor = std::shared_ptr<actor>(new actor(this, pos));
  actors->push_back(new_actor);
  return new_actor;
}

}  // namespace TCODMaze
