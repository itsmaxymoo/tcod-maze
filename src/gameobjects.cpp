#include "gameobjects.hpp"

TCODMaze::GameObject GameObjectRegistrar::FLOOR(' ');
TCODMaze::GameObject GameObjectRegistrar::WALL('#', {200, 200, 200});
TCODMaze::GameObject GameObjectRegistrar::START('S', {200, 150, 150});
TCODMaze::GameObject GameObjectRegistrar::FINISH('F', {0, 200, 0});

const TCODMaze::GameObject* GameObjectRegistrar::mazeTile2GameObject(
    TCODMaze::MazeTile mt) {
  switch (mt) {
    case TCODMaze::MazeTile::WALL:
      return &WALL;
      break;
    case TCODMaze::MazeTile::START:
      return &START;
      break;
    case TCODMaze::MazeTile::FINISH:
      return &FINISH;
      break;

    default:
      return &FLOOR;
      break;
  }
}