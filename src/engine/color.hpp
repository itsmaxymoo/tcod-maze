/*

RGB color type

*/

#ifndef TCOD_MAZE_COLOR
#define TCOD_MAZE_COLOR

#include <cstdint>

namespace TCODMaze {

// Color struct
struct color_t {
  uint8_t r = 0xFF, g = 0xFF, b = 0xFF;

  bool operator==(const color_t &that) {
    return this->r == that.r && this->g == that.g && this->b == that.b;
  }
};

}  // namespace TCODMaze

#endif