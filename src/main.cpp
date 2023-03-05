#include <iostream>

#include "maze.hpp"

int main() {
  TCODMaze::Maze test_maze(9, 3);

  for (int y = 0; y < test_maze.getHeight(); y++) {
    for (int x = 0; x < test_maze.getWidth(); x++) {
      std::cout << (char)test_maze.getTile(x, y);
    }

    std::cout << "\n";
  }
}