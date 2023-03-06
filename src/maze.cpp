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

MazeTile Maze::getTile(const Vector2i &pos) {
  return this->getTile(pos.x, pos.y);
}

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
  this->width = width_cells * 2 + 1;
  this->height = height_cells * 2 + 1;

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
          this->width, std::vector<MazeTile>(this->height, MazeTile::WALL)));

  // --- Generate the actual maze
  Vector2i spos(1, 1);
  std::vector<Vector2i> walls;

  // Mark the first cell
  setTile(spos, MazeTile::FLOOR);
  {
    // Add walls to array
    auto cell_walls = this->getNeighbors(spos);
    walls.insert(walls.end(), cell_walls.begin(), cell_walls.end());
  }

  // Begin regular algorithm
  while (walls.size() > 0) {
    // Pick random wall.
  }
}

void Maze::setTile(const Vector2i &pos, MazeTile tile) {
  this->setTile(pos.x, pos.y, tile);
}

void Maze::setTile(int x, int y, MazeTile tile) {
  (*(this->grid))[x][y] = tile;
}

// Function to get the FOUR neighboring cells of a cell. If they are out of
// bounds, they are ignored.
std::vector<Vector2i> Maze::getNeighbors(Vector2i &pos) {
  const Vector2i DIRECTIONS[] = {Vector2i(0, 1), Vector2i(1, 0),
                                 Vector2i(0, -1), Vector2i(-1, 0)};

  std::vector<Vector2i> neighbors;

  for (Vector2i direction : DIRECTIONS) {
    Vector2i neighbor = pos + direction;
    try {
      getTile(neighbor);
      neighbors.push_back(neighbor);
    } catch (std::domain_error &e) {
      // ignore error; this neighbor doesn't exist
    }
  }

  return neighbors;
}

}  // namespace TCODMaze