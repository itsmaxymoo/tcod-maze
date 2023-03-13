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

}  // namespace TCODMaze
