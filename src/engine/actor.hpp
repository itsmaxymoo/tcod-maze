/*

This file holds classes related to actors.

*/

#ifndef TCOD_MAZE_actor
#define TCOD_MAZE_actor

#include <memory>

#include "action.hpp"
#include "tile.hpp"
#include "vector2i.hpp"

namespace TCODMaze {

// Forward-declares
class scene;

// An actor is generally something player or AI controlled
class actor : public tile_t {
 private:
  std::shared_ptr<action> next_action;
  scene *parent_scene;

 public:
  actor(scene *, vector2i = vector2i(0, 0));

  vector2i position;

  scene *get_parent_scene() const;

  void set_next_action(std::shared_ptr<action>);
  void execute_action();
};

}  // namespace TCODMaze

#endif