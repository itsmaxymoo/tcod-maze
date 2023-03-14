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

// An actor is generally something player or AI controlled
class Actor : public GameObject {
 private:
  float energy = 100.f;
  float energyPenalty = 1.f;
  std::shared_ptr<Action> nextAction;

 public:
  static const float ENERGY_THRESHOLD;

  Vector2i position;

  float getEnergy();
  float getEnergyPenalty();
  std::shared_ptr<Action> getNextAction();

  void setEnergy(float);
  void setEnergyPenalty(float);
  void setNextAction(std::shared_ptr<Action>);
};

}  // namespace TCODMaze

#endif