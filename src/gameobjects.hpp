/*

Declare our game's gameobjects

*/

#ifndef TCOD_MAZE_GAMEOBJECT_REGISTRAR
#define TCOD_MAZE_GAMEOBJECT_REGISTRAR

#include <memory>

#include "engine/gameobject.hpp"
#include "engine/maze.hpp"

namespace GameObjectRegistrar {

static const TCODMaze::GameObject FLOOR;
static const TCODMaze::GameObject WALL;
static const TCODMaze::GameObject START;
static const TCODMaze::GameObject FINISH;

const TCODMaze::GameObject* mazeTile2GameObject(TCODMaze::MazeTile);

}  // namespace GameObjectRegistrar

#endif