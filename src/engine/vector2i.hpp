/*

This file defines a Vector2D object

*/

#ifndef TCOD_MAZE_VECTOR2
#define TCOD_MAZE_VECTOR2

namespace TCODMaze {

struct Vector2i {
  int x = 0, y = 0;
  Vector2i();
  Vector2i(int x, int y);
  bool operator==(const Vector2i &that) const;
  Vector2i operator+(const Vector2i &that);
  Vector2i operator-(const Vector2i &that);
  Vector2i operator*(int);
  Vector2i &operator=(const Vector2i &that);
};

struct Vector2iHash {
  int operator()(const Vector2i &t) const {
    return 0;
  }
};

}  // namespace TCODMaze

#endif