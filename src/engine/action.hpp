/*

This file holds classes related to Actions.

*/

#ifndef TCOD_MAZE_ACTION
#define TCOD_MAZE_ACTION

namespace TCODMaze {

// Forward-declares
class actor;
class scene;

class Action {
 public:
  virtual void execute(actor*);
};

}  // namespace TCODMaze

#endif