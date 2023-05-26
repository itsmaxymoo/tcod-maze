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
#include "gameobject.hpp"
#include "maze.hpp"
#include "tile.hpp"
#include "vector2i.hpp"

namespace TCODMaze {

class scene {
 private:
  std::string name = "";
  tile_t default_tile;
  std::unordered_map<Vector2i, tile_t, Vector2iHash> static_map;
  std::shared_ptr<std::list<std::shared_ptr<Actor>>> actors;

 public:
  // Getters
  const std::string get_name();
  const tile_t get_default_tile();
  std::shared_ptr<std::list<std::shared_ptr<Actor>>> get_actors();
  tile_t get_cell(Vector2i);

  // Setters
  void set_name(std::string);
  void set_default_tile(tile_t);

  // Other
  std::shared_ptr<Actor> create_actor(Vector2i = Vector2i(0, 0));
};

}  // namespace TCODMaze

#endif