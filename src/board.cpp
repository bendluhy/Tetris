#include "board.h"

Board::Board(Renderer* ren)
{
    pRen = ren;
    for(int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 20; y++)
        {
            board[y][x] = 'X';
        }
    }
};
void Board::setBoardSquare(int x, int y, char color)
{
    board[y-1][x-1] = color;
}
char Board::getBoardSquare(int x, int y)
{
    return board[y-1][x-1];
}
void Board::drawBoard()
{
    for(int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 20; y++)
        {
            if (board[y][x] != 'X')
            {
                pRen->renderTetrisBlock(500 + ((x) * 50), (y) * 50, board[y][x]);
            }
        }
    }
}