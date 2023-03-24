/*

This file holds classes related to Actions.

*/

#ifndef TCOD_MAZE_ACTION
#define TCOD_MAZE_ACTION

namespace TCODMaze {

// Forward-declares
class Actor;
class Scene;

class Action {
  virtual void execute(Actor&, Scene&);
};

}  // namespace TCODMaze

#endif