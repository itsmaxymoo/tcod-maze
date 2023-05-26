/*

TCODMaze::scene

*/

#include "scene.hpp"

namespace TCODMaze {

const std::string scene::get_name() { return name; }

const tile_t scene::get_default_tile() { return default_tile; }

std::shared_ptr<std::list<std::shared_ptr<Actor>>> scene::get_actors() {
  return actors;
}

tile_t scene::get_cell(Vector2i pos) {
  if (this->static_map.find(pos) == this->static_map.end()) {
    return this->get_default_tile();
  } else {
    return static_map[pos];
  }
}

void scene::set_name(std::string name) { this->name = name; }

void scene::set_default_tile(tile_t default_tile) {
  this->default_tile = default_tile;
}

std::shared_ptr<Actor> scene::create_actor(Vector2i pos) {
  auto actor = std::shared_ptr<Actor>(new Actor(this, pos));
  actors->push_back(actor);
  return actor;
}

}  // namespace TCODMaze
