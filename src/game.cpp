
#include "game.h"
Game::Game(Renderer* ren)
{
    board = new Board(ren);
}
void Game::tick()
{
    SDL_Delay(1000);
    
};
void Game::spawnNewBlock()
{

};