/*

This class defines the main game loop.

*/

#ifndef TCOD_MAZE_ENGINE
#define TCOD_MAZE_ENGINE

#include <memory>

#include "actor.hpp"
#include "scene.hpp"

namespace TCODMaze {

    enum GameState { PRE, MAIN, LOSE };

    class Engine {
    private:
        GameState state;

    public:
        std::shared_ptr<Scene> scene;
        Actor *player;

        GameState update();
    };
}  // namespace TCODMaze


#endif