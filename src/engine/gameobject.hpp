/*

This file holds classes related to Game Objects.

*/

#ifndef TCOD_MAZE_GAME_OBJECT
#define TCOD_MAZE_GAME_OBJECT

#include <string>

namespace TCODMaze {

// Color struct
typedef struct {
  short r = 0xFF, g = 0xFF, b = 0xFF;
} Color;

// A static "Game Object" - Shows up on the map and not much else.
class GameObject {
 public:
  GameObject();
  GameObject(char);
  GameObject(char, Color);

  char character = '#';             // Ascii representation
  Color color = {255, 255, 255};    // Ascii color
  std::string id = "wall_default";  // GO id; for rendering sprite
  std::string name = "Wall";        // In-game base name
  bool lowRenderPriority = false;   // Should we ignore render if in a stack?
  bool collide = true;
  bool opaque = true;
};
}  // namespace TCODMaze

#endif