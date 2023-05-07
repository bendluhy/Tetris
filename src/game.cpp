
#include "game.h"

Game::Game(Board *board)
{
    pBoard = board;
    pBoard->setBoardSquare(10, 20, 'C');
    pBoard->setBoardSquare(9, 20, 'O');
    pBoard->setBoardSquare(8, 20, 'B');
    pBoard->setBoardSquare(7, 20, 'R');
    pBoard->setBoardSquare(6, 20, 'P');
    pBoard->setBoardSquare(5, 20, 'G');
    pBoard->setBoardSquare(4, 20, 'Y');
}
void Game::tick()
{  
    //array of blocks that need to be moved
    std::vector<std::pair<int,int>> moveblocks = {};

      // polls the whole board to see if there are blocks without any below them
    for (int y = 1; y < 21; y++)
    {
        for (int x = 1; x < 11; x++)
        {
            if (pBoard->getBoardSquare(x, y) != 'X')
            {
                // check if block isn't on the ground
                if (y < 20)
                {
                    // check if space below block is empty
                    if (pBoard->getBoardSquare(x, y + 1) == 'X')
                    {
                        moveblocks.push_back(std::make_pair(x,y));
                    }

                }
            }
        }

    }
    for(int i = 0; i < moveblocks.size(); i++)
    {
        pBoard->setBoardSquare(moveblocks[i].first, moveblocks[i].second + 1, pBoard->getBoardSquare(moveblocks[i].first, moveblocks[i].second));
        pBoard->setBoardSquare(moveblocks[i].first, moveblocks[i].second, 'X');
    }

};
void Game::spawnNewBlock()
{

};
void Game::loop()
{

};