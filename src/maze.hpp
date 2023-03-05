/*

This file defines a Maze/Maze Generator class.

*/

#ifndef TCOD_MAZE_MAZE
#define TCOD_MAZE_MAZE

#include <memory>
#include <vector>

namespace TCODMaze {

enum MazeTile { FLOOR, WALL, START, FINISH };

class Maze {
 private:
  int width;
  int height;
  std::unique_ptr<std::vector<std::vector<MazeTile>>> grid;
  void construct(int width, int height);
  void setTile(int x, int y, MazeTile);

 public:
  static const int MIN_WIDTH, MIN_HEIGHT;
  Maze(int size = MIN_HEIGHT);
  Maze(int width = MIN_WIDTH, int height = MIN_HEIGHT);
  int getWidth();
  int getHeight();
  MazeTile getTile(int x, int y);
};

}  // namespace TCODMaze

#endif