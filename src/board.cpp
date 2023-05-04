#include "board.h"

Board::Board(Renderer* ren)
{
    pRen = ren;
    clearBoard();
    
};
void Board::setBoardSquare(int x, int y, char color)
{
    if(y > 20 || x > 20)
    {
        std::cout << "Your x or y choord is too big\n";
    }
    else 
    {
        board[y - 1][x - 1] = color;
    }
}
char Board::getBoardSquare(int x, int y)
{
    if(y > 21 || x > 11)
    {
        std::cout << "Your x or y choord is too big\n";
        return 'X';
    }
    else 
    {
        return board[y-1][x-1];
    }
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
void Board::clearBoard()
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 20; y++)
        {
            board[y][x] = 'X';
        }
    }
};