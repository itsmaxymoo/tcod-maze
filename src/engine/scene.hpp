/*

This class represent a local area

*/

#ifndef TCOD_MAZE_SCENE
#define TCOD_MAZE_SCENE

#include <list>
#include <memory>
#include <string>
#include <unordered_map>

#include "actor.hpp"
#include "maze.hpp"
#include "tile.hpp"
#include "vector2i.hpp"

namespace TCODMaze {

class scene {
 private:
  std::unordered_map<Vector2i, tile_t, Vector2iHash> static_map;

 public:
  std::string name = "";
  tile_t default_tile;
  std::shared_ptr<std::list<std::shared_ptr<actor>>> actors;

  // Getters
  tile_t get_cell(Vector2i);

  // Factory
  std::shared_ptr<actor> create_actor(Vector2i = Vector2i(0, 0));
};

}  // namespace TCODMaze

#endif