/*

This file defines a Maze/Maze Generator class.

*/

#ifndef TCOD_MAZE_MAZE
#define TCOD_MAZE_MAZE

#include <memory>
#include <vector>

#include "vector2i.hpp"

namespace TCODMaze {

enum MazeTile { FLOOR = ' ', WALL = '#', START = 'S', FINISH = 'F' };

class Maze {
 private:
  int width;
  int height;
  std::unique_ptr<std::vector<std::vector<MazeTile>>> grid;
  void construct(int width, int height);
  void setTile(const Vector2i&, MazeTile);
  void setTile(int x, int y, MazeTile);
  std::vector<Vector2i> getNeighbors(Vector2i&);

 public:
  static const int MIN_WIDTH, MIN_HEIGHT;
  Maze(int width_cells = MIN_WIDTH, int height_cells = MIN_HEIGHT);
  int getWidth();
  int getHeight();
  MazeTile getTile(const Vector2i&);
  MazeTile getTile(int x, int y);
};

}  // namespace TCODMaze

#endif