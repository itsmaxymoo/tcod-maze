/*

Action definitions for our game

*/

#ifndef TCOD_MAZE_CUSTOM_ACTIONS
#define TCOD_MAZE_CUSTOM_ACTIONS

#include "engine/action.hpp"
#include "engine/actor.hpp"
#include "engine/vector2i.hpp"

class move_action : public TCODMaze::action {
 public:
  TCODMaze::vector2i direction;
  move_action();
  move_action(const TCODMaze::vector2i&);
  void execute(TCODMaze::actor*);
};

#endif