/*

This file defines a map tile

*/

#ifndef TCOD_MAZE_TILE
#define TCOD_MAZE_TILE

#include <string>

#include "color.hpp"

namespace TCODMaze {

// A static "Game Object" - Shows up on the map and not much else.
struct tile_t {
  char ascii = '.';
  color_t ascii_color = {0xFF, 0xFF, 0xFF};
  bool collision = false;
  std::string id = "";
  std::string name = "";

  bool operator==(const tile_t &that) {
    return this->ascii == that.ascii && this->ascii_color == that.ascii_color &&
           this->collision == that.collision && this->id == that.id &&
           this->name == that.name;
  }
};

}  // namespace TCODMaze

#endif