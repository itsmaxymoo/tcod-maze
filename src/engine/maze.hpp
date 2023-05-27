/*

This file defines a Maze/Maze Generator class.

*/

#ifndef TCOD_MAZE_MAZE
#define TCOD_MAZE_MAZE

#include <memory>
#include <random>
#include <vector>

#include "tile.hpp"
#include "vector2i.hpp"

namespace TCODMaze {

class TILES {
 public:
  static tile_t FLOOR;
  static tile_t WALL;
  static tile_t START;
  static tile_t FINISH;
  static tile_t VOID;
};

class maze {
 private:
  static std::mt19937 rng;
  int width;
  int height;
  std::unique_ptr<std::vector<std::vector<tile_t>>> grid;
  void construct(int width, int height);
  void set_tile(const vector2i&, tile_t);
  void set_tile(int x, int y, tile_t);
  std::vector<vector2i> get_neighbors(vector2i&);

 public:
  static const int MIN_WIDTH, MIN_HEIGHT;
  maze(int width_cells = MIN_WIDTH, int height_cells = MIN_HEIGHT);
  int get_width();
  int get_height();
  tile_t get_tile(const vector2i&) const;
  tile_t get_tile(int x, int y) const;
};

}  // namespace TCODMaze

#endif