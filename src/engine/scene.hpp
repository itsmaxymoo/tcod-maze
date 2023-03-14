/*

This class represent a local area

*/

#ifndef TCOD_MAZE_SCENE
#define TCOD_MAZE_SCENE

#include <list>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

#include "actor.hpp"
#include "gameobject.hpp"
#include "vector2i.hpp"

namespace TCODMaze {

class Scene {
 private:
  std::string name = "";
  std::shared_ptr<GameObject> defaultGameObject;
  std::unordered_map<Vector2i, std::list<std::shared_ptr<GameObject>>>
      staticMap;
  std::shared_ptr<std::vector<std::shared_ptr<Actor>>> actors;

 public:
  // Getters
  const std::string getName();
  const std::shared_ptr<GameObject> getDefaultGameObject();
  std::vector<Actor> getActors();
  std::weak_ptr < std::list < std::shared_ptr < GameObject >>>>
      getMapCell(Vector2i pos);

  // Setters
  void setName(std::string);
  void setDefaultGameObject(
      std::shared_ptr<std::vector<std::shared_ptr<Actor>>>);
}

}  // namespace TCODMaze

#endif