#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "renderer.h"
#include <iostream>

class Game
{
    private:
        void spawnNewBlock();
    public:
        Board* pBoard;
        Game(Renderer* ren, Board* board);
        void tick();
        void pollKeystrokes();
        void loop();
};

#endif