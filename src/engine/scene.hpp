/*

This class represent a local area

*/

#ifndef TCOD_MAZE_SCENE
#define TCOD_MAZE_SCENE

#include <list>
#include <memory>
#include <string>
#include <unordered_map>

#include "actor.hpp"
#include "gameobject.hpp"
#include "maze.hpp"
#include "vector2i.hpp"

namespace TCODMaze {

class Scene {
 private:
  std::string name = "";
  MazeTile defaultMazeTile;
  std::unordered_map<Vector2i, MazeTile, Vector2iHash> staticMap;
  std::shared_ptr<std::list<std::shared_ptr<Actor>>> actors;

 public:
  // Getters
  const std::string getName();
  const MazeTile getDefaultMazeTile();
  std::shared_ptr<std::list<std::shared_ptr<Actor>>> getActors();
  MazeTile getCell(Vector2i);

  // Setters
  void setName(std::string);
  void setDefaultMazeTile(MazeTile);

  // Other
  std::weak_ptr<Actor> createActor(Vector2i = Vector2i(0, 0));
};

}  // namespace TCODMaze

#endif