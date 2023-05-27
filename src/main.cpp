#include <iostream>

#include "engine/engine.hpp"
#include "tcod_frontend.hpp"
#include "engine/maze.hpp"
#include "engine/tile.hpp"

int main() {
  TCODMaze::tile_t fin = TCODMaze::TILES::FINISH;
  TCODMaze::tile_t fin2 = fin;

  TCODMaze::Engine engine;
  TCODAsciiFrontEnd frontend;

  frontend.run(&engine);

  return 0;
}