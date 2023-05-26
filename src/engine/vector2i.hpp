/*

This file defines a Vector2D object

*/

#ifndef TCOD_MAZE_VECTOR2
#define TCOD_MAZE_VECTOR2

#include <cstdint>
#include <functional>

namespace TCODMaze {

struct vector2i {
  int32_t x = 0, y = 0;
  vector2i();
  vector2i(uint32_t x, uint32_t y);
  bool operator==(const vector2i &that) const;
  vector2i operator+(const vector2i &that);
  vector2i operator-(const vector2i &that);
  vector2i operator*(int);
  vector2i &operator=(const vector2i &that);
};

struct vector2i_hash {
  int operator()(const vector2i &t) const;
};

}  // namespace TCODMaze

#endif