#include "gameobject.hpp"

namespace TCODMaze {

/*

TCODMaze::GameObject

*/

GameObject::GameObject(){};

GameObject::GameObject(char ascii) { this->character = ascii; }

GameObject::GameObject(char ascii, Color color) {
  this->character = ascii;
  this->color = color;
}

}  // namespace TCODMaze
