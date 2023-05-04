
#include<math.h>
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "renderer.h"
#include "game.h"
#include "board.h"
#include <thread>

int main()
{
	std::cout << "Launching Tetris\n";
	SDL_Window *window = SDL_CreateWindow(
		"Tetris",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1500,
		1000,
		0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	Renderer* pRen = new Renderer(renderer);
	Board* board= new Board(pRen);
	Game* game = new Game(pRen, board);
	board->setBoardSquare(2,2,'G');
	board->setBoardSquare(2,1,'R');
	bool isOn = true;
	while (isOn)
	{
		//render walls
		for (int y = 0; y < 1501; y += 50)
		{
			pRen->renderTetrisBlock(450,y,'g');
		}
		for (int y = 0; y < 1501; y += 50)
		{
			pRen->renderTetrisBlock(1000,y,'g');
		}
		
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isOn = false;
			}
			if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
			{
				isOn = false;
			}
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			{
				isOn = false;
			}
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d)
			{
			}
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a)
			{
			}
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_w)
			{
			}
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s)
			{

			}
		}
		game->tick();
		board->drawBoard();
		SDL_RenderPresent(renderer);
		pRen->clearScreen();
	}
	delete game;
	delete pRen;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
