/*

This class defines the main game loop.

*/

#ifndef TCOD_MAZE_ENGINE
#define TCOD_MAZE_FRONTEND

namespace TCODMaze {

#include <memory>

#include "actor.hpp"
#include "scene.hpp"

    enum GameState { PRE, MAIN, LOSE };

    class Engine {
    private:
        GameState state;

    public:
        std::shared_ptr<Scene> scene;
        std::weak_ptr<Actor> player;

        GameState update();
    };
}  // namespace TCODMaze


#endif