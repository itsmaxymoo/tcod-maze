#include "maze.hpp"

#include <ctime>
#include <stdexcept>

namespace TCODMaze {

// --- Declare tile types
tile_t TILES::FLOOR = {' ', {0xFF, 0xFF, 0xFF}};
tile_t TILES::WALL = {'#', {0xF0, 0xF0, 0xF0}, true};
tile_t TILES::START = {'S', {0xFF, 0xA0, 0xA0}};
tile_t TILES::FINISH = {'F', {0x0, 0xFF, 0x0}};
tile_t TILES::VOID = {' ', {0x0, 0x0, 0x0}, true};

// --- Constants
const int maze::MIN_WIDTH = 1;
const int maze::MIN_HEIGHT = 1;

// --- RNG
std::mt19937 maze::rng(time(NULL));

// --- Public ---

maze::maze(int width_cells, int height_cells) {
  this->construct(width_cells, height_cells);
}

int maze::get_width() { return this->width; }
int maze::get_height() { return this->height; }

tile_t maze::get_tile(const vector2i &pos) const {
  return this->get_tile(pos.x, pos.y);
}

tile_t maze::get_tile(int x, int y) const {
  // Check bounds
  if (x < 0 || x >= this->width || y < 0 || y >= this->height)
    throw std::domain_error("Out of bounds maze cell access");

  return this->grid->get_cell(vector2i(x, y));
}

std::shared_ptr<scene> maze::get_scene() const { return this->grid; }

// --- Private ---

// This function generates the actual maze
void maze::construct(int width_cells, int height_cells) {
  // Convert "cell size" to actual grid size
  this->width = width_cells * 2 + 1;
  this->height = height_cells * 2 + 1;

  // Make sure maze is wide enough
  if (width_cells < MIN_WIDTH)
    throw std::domain_error(
        "maze width too small: " + std::to_string(width_cells) + "<" +
        std::to_string(MIN_WIDTH));
  // Make sure maze is tall enough
  if (height_cells < MIN_HEIGHT)
    throw std::domain_error(
        "maze height too small: " + std::to_string(height_cells) + "<" +
        std::to_string(MIN_HEIGHT));

  // Create grid scene
  this->grid = std::make_shared<scene>();
  this->grid->default_tile = TILES::VOID;
  for (int i = 0; i < this->width; ++i)
    for (int j = 0; j < this->height; ++j)
      this->grid->set_cell(vector2i(i, j), TILES::WALL);

  // --- Generate the actual maze
  vector2i spos(1, 1);
  std::vector<vector2i> walls;

  // Mark the first cell
  set_tile(spos, TILES::FLOOR);
  {
    // Add walls to array
    walls = this->get_neighbors(spos);
  }

  // Begin regular algorithm
  while (!walls.empty()) {
    // Get random wall
    std::uniform_int_distribution<int> allWallsRange(0, walls.size() - 1);
    int selectedWallIndex = allWallsRange(maze::rng);
    vector2i selectedWall = walls[selectedWallIndex];

    // Get wall's neighbors (cells)
    std::vector<vector2i> neighboringCells = this->get_neighbors(selectedWall);

    // Count visited neighbors
    int visitedNeighbors = 0;
    vector2i visitedNeighbor;
    for (vector2i neighboringCell : neighboringCells) {
      if (this->get_tile(neighboringCell) == TILES::FLOOR) {
        visitedNeighbors++;

        visitedNeighbor.x = neighboringCell.x;
        visitedNeighbor.y = neighboringCell.y;
      }
    }

    // If there is only one visited neighbor
    if (visitedNeighbors == 1) {
      // Find coords of opposing cell
      vector2i opposingCell = selectedWall + (selectedWall - visitedNeighbor);

      try {
        // Mark opposing cell
        this->set_tile(opposingCell, TILES::FLOOR);
        // Mark this wall as floor
        this->set_tile(selectedWall, TILES::FLOOR);

        // Add opposing cell's walls to the list
        for (vector2i opposingCellNeighborWall :
             this->get_neighbors(opposingCell))
          if (this->get_tile(opposingCellNeighborWall) == TILES::WALL)
            walls.push_back(opposingCellNeighborWall);
      } catch (std::domain_error &e) {
        // This wall must have been a border cell. Ignore.
      }
    }

    // Remove this wall from the walls list
    std::swap(walls[selectedWallIndex], walls[walls.size() - 1]);
    walls.pop_back();
  }

  // --- End Prim's

  // Set the start and end points
  this->set_tile(0, 1, TILES::START);
  this->set_tile(this->width - 1, this->height - 2, TILES::FINISH);
}

void maze::set_tile(const vector2i &pos, tile_t tile) {
  this->set_tile(pos.x, pos.y, tile);
}

void maze::set_tile(int x, int y, tile_t tile) {
  this->get_tile(x, y);
  this->grid->set_cell(vector2i(x, y), tile);
}

// Function to get the FOUR neighboring cells of a cell. If they are out of
// bounds, they are ignored.
std::vector<vector2i> maze::get_neighbors(vector2i &pos) {
  const vector2i DIRECTIONS[] = {vector2i(0, 1), vector2i(1, 0),
                                 vector2i(0, -1), vector2i(-1, 0)};

  std::vector<vector2i> neighbors;

  for (vector2i direction : DIRECTIONS) {
    vector2i neighbor = pos + direction;
    try {
      get_tile(neighbor);
      neighbors.push_back(neighbor);
    } catch (std::domain_error &e) {
      // ignore error; this neighbor doesn't exist
    }
  }

  return neighbors;
}

}  // namespace TCODMaze