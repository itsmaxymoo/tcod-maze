/*

This file holds classes related to actions.

*/

#ifndef TCOD_MAZE_ACTION
#define TCOD_MAZE_ACTION

namespace TCODMaze {

// Forward-declares
class actor;
class scene;

class action {
 public:
  virtual void execute(actor*);
};

}  // namespace TCODMaze

#endif