#include "vector2.hpp"

namespace TCODMaze {
Vector2::Vector2() {}
Vector2::Vector2(int x, int y) {
  this->x = x;
  this->y = y;
}

bool Vector2::operator==(const Vector2 &that) {
  return this->x == that.x && this->y == that.y;
}

Vector2 Vector2::operator+(const Vector2 &that) {
  return Vector2(this->x + that.x, this->y + that.y);
}

Vector2 Vector2::operator-(const Vector2 &that) {
  return Vector2(this->x - that.x, this->y - that.y);
}

Vector2 Vector2::operator*(int a) { return Vector2(this->x * a, this->y * a); }

}  // namespace TCODMaze
