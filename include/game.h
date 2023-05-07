#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "renderer.h"
#include <iostream>
#include <vector>

class Game
{
    private:
        void spawnNewBlock();
    public:
        Board* pBoard;
        Game(Board* board);
        void tick();
        void pollKeystrokes();
        void loop();
};

#endif