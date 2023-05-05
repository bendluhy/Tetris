#include "board.h"
#include "mutexHelper.h"

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
        mtx.lock();
        board[y - 1][x - 1] = color;
        mtx.unlock();
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
    //Render the walls 
    for (int y = 0; y < 1501; y += 50)
    {
        
        pRen->renderTetrisBlock(450, y, 'g');
    }
    for (int y = 0; y < 1501; y += 50)
    {
        pRen->renderTetrisBlock(1000, y, 'g');
    }

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
            mtx.lock();
            board[y][x] = 'X';
            mtx.unlock();
        }
    }
};