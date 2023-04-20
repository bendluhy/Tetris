#ifndef BOARD_H
#define BOARD_H
#include "renderer.h"
class Board
{
    public:
        Board(Renderer* ren);
        Renderer* pRen; 
        char board[20][10];
        char getBoardSquare(int x, int y);
        void drawSquare(int width, int height, char color);
        void setBoardSquare(int x, int y, char color);
        void drawBoard();
        void clearBoard();
    
};
#endif