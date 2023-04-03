/*

This file/class houses the "front end" code

*/

#ifndef TCOD_MAZE_FRONTEND
#define TCOD_MAZE_FRONTEND

#include <memory>

#include "engine/engine.hpp"

namespace TCODMaze {

class FrontEnd {
 public:
  virtual void run(Engine&);
};

class TCODAsciiFrontEnd : public FrontEnd {
 public:
  void run(Engine&);
};

}  // namespace TCODMaze

#endif