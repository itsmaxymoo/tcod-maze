/*

This file defines a Vector2D object

*/

#ifndef TCOD_MAZE_VECTOR2
#define TCOD_MAZE_VECTOR2

namespace TCODMaze {

class Vector2i {
 public:
  int x = 0, y = 0;
  Vector2i();
  Vector2i(int x, int y);
  bool operator==(const Vector2i &that);
  Vector2i operator+(const Vector2i &that);
  Vector2i operator-(const Vector2i &that);
  Vector2i operator*(int);
};

}  // namespace TCODMaze

#endif