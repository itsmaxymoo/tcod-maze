#include "maze.hpp"

#include <stdexcept>

namespace TCODMaze {

// --- Constants

const int Maze::MIN_WIDTH = 6;
const int Maze::MIN_HEIGHT = 6;

// --- Public ---

Maze::Maze(int size) { this->construct(size, size); }
Maze::Maze(int width, int height) { this->construct(width, height); }

int Maze::getWidth() { return this->width; }
int Maze::getHeight() { return this->height; }

MazeTile Maze::getTile(int x, int y) { return (*(this->grid))[x][y]; }

// --- Private ---

// This function generates the actual maze
void Maze::construct(int width, int height) {
  // Make sure maze is wide enough
  if (width < MIN_WIDTH)
    throw std::domain_error("Maze width too small: " + std::to_string(width) +
                            "<" + std::to_string(MIN_WIDTH));
  // Make sure maze is tall enough
  if (width < MIN_WIDTH)
    throw std::domain_error("Maze height too small: " + std::to_string(height) +
                            "<" + std::to_string(MIN_HEIGHT));

  // Create grid vector (yikes)
  this->grid = std::make_unique<std::vector<std::vector<MazeTile>>>(
      std::vector<std::vector<MazeTile>>(
          height, std::vector<MazeTile>(width, MazeTile::WALL)));

  // TODO: Generate the actual maze
}

void Maze::setTile(int x, int y, MazeTile tile) {
  (*(this->grid))[x][y] = tile;
}

}  // namespace TCODMaze