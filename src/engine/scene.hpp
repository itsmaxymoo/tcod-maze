/*

This class represent a local area

*/

#ifndef TCOD_MAZE_SCENE
#define TCOD_MAZE_SCENE

#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include <list>

#include "actor.hpp"
#include "gameobject.hpp"
#include "vector2i.hpp"

namespace TCODMaze {

class Scene {
 private:
  std::string name = "";
  std::shared_ptr<GameObject> defaultGameObject;
  std::unordered_map<Vector2i, std::shared_ptr<GameObject>> staticMap;
  std::shared_ptr<std::list<std::shared_ptr<Actor>>> actors;

 public:
  // Getters
  const std::string getName();
  const std::shared_ptr<GameObject> getDefaultGameObject();
  std::shared_ptr<std::list<std::shared_ptr<Actor>>> getActors();
  std::shared_ptr<GameObject> getCell(Vector2i);

  // Setters
  void setName(std::string);
  void setDefaultGameObject(std::shared_ptr<GameObject>);
};

}  // namespace TCODMaze

#endif