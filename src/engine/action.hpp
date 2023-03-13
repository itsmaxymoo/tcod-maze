/*

This file holds classes related to Actions.

*/

#ifndef TCOD_MAZE_ACTION
#define TCOD_MAZE_ACTION

namespace TCODMaze {

// Forward-declares
class Actor;

class Action {
  virtual void execute(Actor&);
};

}  // namespace TCODMaze

#endif