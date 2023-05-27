/*

TCODMaze::actor

*/

#include "actor.hpp"

namespace TCODMaze {

// Constructor
actor::actor(scene* parent_scene, vector2i position) {
  this->parent_scene = parent_scene;
  this->position = position;
}

scene* actor::get_parent_scene() const { return this->parent_scene; }

void actor::set_next_action(std::shared_ptr<action> x) {
  this->next_action = x;
}

void actor::execute_action() {
  if (this->next_action != nullptr) {
    this->next_action.get()->execute(this);
    this->next_action = nullptr;
  }
}
}  // namespace TCODMaze
