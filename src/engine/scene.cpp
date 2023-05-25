/*

TCODMaze::Scene

*/

#include "scene.hpp"

namespace TCODMaze {

const std::string Scene::getName() { return name; }

const MazeTile Scene::getDefaultMazeTile() { return defaultMazeTile; }

std::shared_ptr<std::list<std::shared_ptr<Actor>>> Scene::getActors() {
  return actors;
}

MazeTile Scene::getCell(Vector2i pos) {
  if (this->staticMap.find(pos) == this->staticMap.end()) {
    return this->getDefaultMazeTile();
  } else {
    return staticMap[pos];
  }
}

void Scene::setName(std::string name) { this->name = name; }

void Scene::setDefaultMazeTile(MazeTile defaultMazeTile) {
  this->defaultMazeTile = defaultMazeTile;
}

std::weak_ptr<Actor> Scene::createActor(Vector2i pos) {
  auto actor = std::shared_ptr<Actor>(new Actor(this, pos));
  actors->push_back(actor);
  return std::weak_ptr<Actor>(actor);
}

}  // namespace TCODMaze
