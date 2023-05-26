/*

TCODMaze::Actor

*/

#include "actor.hpp"

namespace TCODMaze {
// Constants
const float Actor::ENERGY_THRESHOLD = 100.f;

// Constructor
Actor::Actor(scene *this_scene, Vector2i position) {
  this->this_scene = this_scene;
  this->position = position;
}

// Getters
std::shared_ptr<Action> Actor::getNextAction() { return this->nextAction; }

// Setters
void Actor::setNextAction(std::shared_ptr<Action> x) { this->nextAction = x; }
}  // namespace TCODMaze
