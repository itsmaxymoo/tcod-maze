#include <iostream>

#include "engine/engine.hpp"
#include "tcod_frontend.hpp"

int main() {
  TCODMaze::Engine engine;
  TCODAsciiFrontEnd frontend;

  frontend.run(&engine);

  return 0;
}