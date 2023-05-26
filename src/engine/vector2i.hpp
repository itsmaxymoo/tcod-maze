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
  int operator()(const vector2i &t) const {
    int64_t xl = (int64_t)t.x + INT32_MAX, yl = (int64_t)t.y + INT32_MAX;
    return std::hash<int>()(xl) ^ std::hash<int>()(yl);
  }
};

}  // namespace TCODMaze

#endif