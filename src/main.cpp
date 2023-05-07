
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_thread.h"

#include "gfx/window.h"
#include "game.h"

//just declare like a hella bunch of data to the heap no biggie

//controls loop in window function
bool running = true;

SDL_Window *win = SDL_CreateWindow(
		"Tetris",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1500,
		1000,
		0);
SDL_Renderer *pSRen = SDL_CreateRenderer(win,-1, SDL_RENDERER_SOFTWARE);
Renderer *pRen = new Renderer(pSRen);
Board *pBoard = new Board(pRen);
int main()
{

	SDL_Thread *pThread = SDL_CreateThread(window, "Window", NULL);
	Game *pGame = new Game(pBoard);
	pBoard->setBoardSquare(1,1, 'B');
	pBoard->setBoardSquare(1,2, 'R');
	while(running)
	{
		pGame->tick();
		SDL_Delay(1000);
	}
	SDL_WaitThread(pThread, NULL);
	return 0;
}