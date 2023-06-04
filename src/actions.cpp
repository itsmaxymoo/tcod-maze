/*

Custom actions implementation

*/

#include "actions.hpp"

#include "engine/actor.hpp"
#include "engine/scene.hpp"
#include "engine/vector2i.hpp"

move_action::move_action() { this->direction = TCODMaze::vector2i(0, 0); }

move_action::move_action(const TCODMaze::vector2i& dir) {
  this->direction = dir;
}

void move_action::execute(TCODMaze::actor* subject) {
  TCODMaze::vector2i new_pos = subject->position + this->direction;

  if (!(subject->get_parent_scene()->get_cell(new_pos).collision)) {
    subject->position = new_pos;
  }
}