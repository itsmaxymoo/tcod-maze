/*

TCODMaze::Actor

*/

#include "actor.hpp"

#include "scene.hpp"

namespace TCODMaze {
// Constants
const float Actor::ENERGY_THRESHOLD = 100.f;

// Constructor
Actor::Actor(Scene& scene, Vector2i position) {
  scene.getActors()->push_front(&this);
  this->position = position;
}

// Getters
std::shared_ptr<Action> Actor::getNextAction() { return this->nextAction; }

// Setters
void Actor::setNextAction(std::shared_ptr<Action> x) { this->nextAction = x; }
}  // namespace TCODMaze
