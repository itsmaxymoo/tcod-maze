/*

This file/class houses the "front end" code

*/

#ifndef TCOD_MAZE_ENGINE_FRONTEND
#define TCOD_MAZE_ENGINE_FRONTEND

#include "engine.hpp"

namespace TCODMaze {

class FrontEnd {
 public:
  virtual int run(Engine*);
};

}  // namespace TCODMaze

#endif