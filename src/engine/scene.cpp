/*

TCODMaze::Scene

*/

#include "scene.hpp"

namespace TCODMaze {

const std::string Scene::getName() { return name; }

const std::shared_ptr<GameObject> Scene::getDefaultGameObject() {
  return defaultGameObject;
}

std::shared_ptr<std::list<std::shared_ptr<Actor>>> Scene::getActors() {
  return actors;
}

std::shared_ptr<GameObject> Scene::getCell(Vector2i pos) {
  return staticMap[pos];
}

void Scene::setName(std::string name) { this->name = name; }

void Scene::setDefaultGameObject(
    std::shared_ptr<GameObject> defaultGameObject) {
  this->defaultGameObject = defaultGameObject;
}

std::weak_ptr<Actor> Scene::createActor(Vector2i pos) {
  auto actor = std::make_shared<Actor>(pos);
  actors->push_back(actor);
  return std::weak_ptr<Actor>(actor);
}

}  // namespace TCODMaze
