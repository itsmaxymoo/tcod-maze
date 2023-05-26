/*

This file holds classes related to Actors.

*/

#ifndef TCOD_MAZE_ACTOR
#define TCOD_MAZE_ACTOR

#include <memory>

#include "action.hpp"
#include "gameobject.hpp"
#include "vector2i.hpp"

namespace TCODMaze {

// Forward-declares
class scene;

// An actor is generally something player or AI controlled
class Actor : public GameObject {
 private:
  std::shared_ptr<Action> nextAction;
  scene *this_scene;

 public:
  static const float ENERGY_THRESHOLD;

  Actor(scene *, Vector2i = Vector2i(0, 0));

  Vector2i position;
  std::shared_ptr<Action> getNextAction();

  void setNextAction(std::shared_ptr<Action>);
};

}  // namespace TCODMaze

#endif