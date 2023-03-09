#include "gameobject.hpp"

namespace TCODMaze {

/*

TCODMaze::GameObject

*/

// Getters
char GameObject::getChar() { return this->character; }
std::string GameObject::getId() { return this->id; }
std::string GameObject::getName() { return this->name; }
bool GameObject::isLowRenderPriority() { return this->lowRenderPriority; }
bool GameObject::isCollide() { return this->collide; }
bool GameObject::isOpaque() { return this->opaque; }

// Setters
void GameObject::setChar(char x) { this->character = x; }
void GameObject::setId(std::string x) { this->id = x; }
void GameObject::setName(std::string x) { this->name = x; }
void GameObject::setLowRenderPriority(bool x) { this->lowRenderPriority = x; }
void GameObject::setCollide(bool x) { this->collide = x; }
void GameObject::setOpaque(bool x) { this->opaque = x; }

/*

TCODMaze::Actor

*/

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
