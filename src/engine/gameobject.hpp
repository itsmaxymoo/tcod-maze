/*

This file holds classes related to Game Objects.

*/

#ifndef TCOD_MAZE_GAME_OBJECT
#define TCOD_MAZE_GAME_OBJECT

#include <string>

#include "action.hpp"

namespace TCODMaze{

// A static "Game Object" - Shows up on the map and not much else.
class GameObject {
 private:
  char character = '#';             // Ascii representation
  std::string id = "wall_default";  // GO id; for rendering sprite
  std::string name = "Wall";        // In-game base name
  bool lowRenderPriority = false;   // Should we ignore render if in a stack?
  bool collide = true;
  bool opaque = true;

 public:
  char getChar();
  std::string getId();
  std::string getName();
  bool isLowRenderPriority();
  bool isCollide();
  bool isOpaque();

  void setChar(char);
  void setId(std::string);
  void setName(std::string);
  void setLowRenderPriority(bool);
  void setCollide(bool);
  void setOpaque(bool);
};
}  // namespace TCODMaze

#endif