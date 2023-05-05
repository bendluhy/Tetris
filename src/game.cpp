#include "mutexHelper.h"

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
            //Check if block isn't empty
            if(pBoard->getBoardSquare(x,y) != 'X')
            {
                //check if block isn't on the ground
                if (y < 20)
                {
                    //check if space below block is empty
                    if (pBoard->getBoardSquare(x, y + 1) == 'X')
                    {
                        std::cout << "Drop occuring at " << x << ":" << y << "->" << x << ":" << y +1 << "\n";

                        //set the space below as block and set the old space as empty
                        pBoard->setBoardSquare(x, y + 1, pBoard->getBoardSquare(x, y));
                        pBoard->setBoardSquare(x, y, 'X');
                        pBoard->drawBoard();
                    }
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