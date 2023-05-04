
#include "game.h"
Game::Game(Renderer *ren, Board *board)
{
    pBoard = board;
    pBoard->setBoardSquare(10,20,'C');
	pBoard->setBoardSquare(9,20,'O');
	pBoard->setBoardSquare(8,20, 'B');
	pBoard->setBoardSquare(7,20, 'R');
	pBoard->setBoardSquare(6,20, 'P');
	pBoard->setBoardSquare(5,20, 'G');
	pBoard->setBoardSquare(4,20, 'Y');
}
void Game::tick()
{
    //polls the whole board to see if there are blocks without any below them
    for (int x = 1; x < 11; x++)
    {
        for (int y = 1; y < 21; y++)  
        {
            std::cout << x << ":" << y << "\n";
            if (y < 20)
            {
                
                if (pBoard->getBoardSquare(x, y + 1) == 'X')
                {
                    std::cout << "Drop occuring at " << x << ":" << y << "\n";
                    pBoard->setBoardSquare(x, y + 1, pBoard->getBoardSquare(x, y));
                    pBoard->setBoardSquare(x,y, 'X');
                    pBoard->drawBoard();
                }
            }
        }
    }
    
};
void Game::spawnNewBlock(){

};
void Game::loop()
{
    while (true)
    {

        tick();
    };
};