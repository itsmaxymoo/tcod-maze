/*

This file defines a Vector2D object

*/

#ifndef TCOD_MAZE_VECTOR2
#define TCOD_MAZE_VECTOR2

namespace TCODMaze {

class Vector2 {
 public:
  int x = 0, y = 0;
  Vector2();
  Vector2(int x, int y);
  bool operator==(const Vector2 &that);
  Vector2 operator+(const Vector2 &that);
  Vector2 operator-(const Vector2 &that);
  Vector2 operator*(int);
};

}  // namespace TCODMaze

#endif