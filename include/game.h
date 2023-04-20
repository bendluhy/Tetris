#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "renderer.h"
class Game
{
    private:
        void spawnNewBlock();
        Board* board;
    public:
        Game(Renderer* ren);
        void tick();
        void pollKeystrokes();
};

#endif