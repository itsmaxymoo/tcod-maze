#include "vector2i.hpp"

#include <algorithm>

namespace TCODMaze {
Vector2i::Vector2i() {}
Vector2i::Vector2i(int x, int y) {
  this->x = x;
  this->y = y;
}

bool Vector2i::operator==(const Vector2i &that) const {
  return this->x == that.x && this->y == that.y;
}

Vector2i Vector2i::operator-(const Vector2i &that) {
  return Vector2i(this->x - that.x, this->y - that.y);
}

Vector2i Vector2i::operator*(int a) {
  return Vector2i(this->x * a, this->y * a);
}

Vector2i &Vector2i::operator=(const Vector2i &that) {
  this->x = that.x;
  this->y = that.y;

  return *this;
}

}  // namespace TCODMaze