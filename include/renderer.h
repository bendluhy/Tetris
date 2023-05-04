
#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>
#include <iostream>
class Renderer
{
    public:
        const int blocksize = 50;
        SDL_Renderer* renderer;
        Renderer(SDL_Renderer* pRen);
        void drawSquare(int x, int y, int h, int w, int r, int g, int b);
        void renderTetrisBlock(int x, int y, char c);
        void renderTetrimino(int x, int y, char block);
        void clearScreen();
};
#endif