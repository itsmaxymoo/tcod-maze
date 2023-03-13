/*

TCODMaze::Actor

*/

#include "actor.hpp"

namespace TCODMaze {
// Constants
const float Actor::ENERGY_THRESHOLD = 100.f;

// Getters
float Actor::getEnergy() { return this->energy; }
float Actor::getEnergyPenalty() { return this->energyPenalty; }
std::shared_ptr<Action> Actor::getNextAction() { return this->nextAction; }

// Setters
void Actor::setEnergy(float x) { this->energy = x; }
void Actor::setEnergyPenalty(float x) { this->energyPenalty = x; }
void Actor::setNextAction(std::shared_ptr<Action> x) { this->nextAction = x; }
}  // namespace TCODMaze
