#include "vector2i.hpp"

#include <algorithm>

namespace TCODMaze {
vector2i::vector2i() {}
vector2i::vector2i(int x, int y) {
  this->x = x;
  this->y = y;
}

bool vector2i::operator==(const vector2i &that) const {
  return this->x == that.x && this->y == that.y;
}

vector2i vector2i::operator+(const vector2i &that) {
  return vector2i(this->x + that.x, this->y + that.y);
}

vector2i vector2i::operator-(const vector2i &that) {
  return vector2i(this->x - that.x, this->y - that.y);
}

vector2i vector2i::operator*(int a) {
  return vector2i(this->x * a, this->y * a);
}

vector2i &vector2i::operator=(const vector2i &that) {
  this->x = that.x;
  this->y = that.y;

  return *this;
}

}  // namespace TCODMaze
