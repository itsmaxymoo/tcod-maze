#include "maze.hpp"

#include <stdexcept>

namespace TCODMaze {

// --- Constants

const int Maze::MIN_WIDTH = 1;
const int Maze::MIN_HEIGHT = 1;

// --- Public ---

Maze::Maze(int width_cells, int height_cells) {
  this->construct(width_cells, height_cells);
}

int Maze::getWidth() { return this->width; }
int Maze::getHeight() { return this->height; }

MazeTile Maze::getTile(int x, int y) {
  // Check bounds
  if (x < 0 || x >= this->width || y < 0 || y >= this->height)
    throw std::domain_error("Out of bounds maze cell access");

  return (*(this->grid))[x][y];
}

// --- Private ---

// This function generates the actual maze
void Maze::construct(int width_cells, int height_cells) {
  // Convert "cell size" to actual grid size
  int width = width_cells * 2 - 1;
  int height = height_cells * 2 - 1;

  this->width = width;
  this->height = height;

  // Make sure maze is wide enough
  if (width_cells < MIN_WIDTH)
    throw std::domain_error(
        "Maze width too small: " + std::to_string(width_cells) + "<" +
        std::to_string(MIN_WIDTH));
  // Make sure maze is tall enough
  if (height_cells < MIN_HEIGHT)
    throw std::domain_error(
        "Maze height too small: " + std::to_string(height_cells) + "<" +
        std::to_string(MIN_HEIGHT));

  // Create grid vector (yikes)
  this->grid = std::make_unique<std::vector<std::vector<MazeTile>>>(
      std::vector<std::vector<MazeTile>>(
          width, std::vector<MazeTile>(height, MazeTile::WALL)));

  // TODO: Generate the actual maze
}

void Maze::setTile(int x, int y, MazeTile tile) {
  (*(this->grid))[x][y] = tile;
}

}  // namespace TCODMaze