/*

This file/class houses the "front end" code

*/

#ifndef TCOD_MAZE_FRONTEND
#define TCOD_MAZE_FRONTEND

#include <memory>

#include "engine/engine.hpp"
#include "engine/frontend.hpp"

class TCODAsciiFrontEnd : public TCODMaze::FrontEnd {
 public:
  int run(TCODMaze::Engine*);
};

#endif