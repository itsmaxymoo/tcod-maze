# tcod-maze

A simple maze game in C++ using libtcod.
I wrote this project to familiarize myself with C++.
It is not meant to be that glamorous!

## How to Play

1. Clone this repo
2. run `./quickbuild.sh`
3. then `./bin/tcod-maze`

Note: The executable must be able to find the `data/` directory!

Use arrow keys to control the character `@`
and make your way to the Finish. You will race the clock and the
maze will get bigger each round, so I hope you're sharp!

## Internals

This project is the basis for a turn-based game engine
I'm working on. The core logic is in the `src/engine/`
directory. The project-specific logic that handles
rendering and input is in the `src/` root. Please note
a lot of the realtime code will be stripped out for the
generic engine.
