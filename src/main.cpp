#include <iostream>

#include "engine/engine.hpp"
#include "frontend.hpp"

int main() {
  TCODMaze::Engine engine;
  TCODMaze::TCODAsciiFrontEnd frontend;

  frontend.run(&engine);

  return 0;
}