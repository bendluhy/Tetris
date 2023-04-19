
#include<math.h>
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "renderer.h"
#include "board.h"

int main()
{
	std::cout << "Launching tetris";
	SDL_Window *window = SDL_CreateWindow(
		"Tetris",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1500,
		1000,
		0);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	
	Renderer* pRen = new Renderer(renderer);
	Board* board = new Board(pRen);
	bool isOn = true;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	int blocx = 50;
	int blocy = 50;
	board->setBoardSquare(10,20,'C');
	board->setBoardSquare(9,20,'O');
	board->setBoardSquare(8,20, 'B');
	board->setBoardSquare(7,20, 'R');
	board->setBoardSquare(6,20, 'P');
	board->setBoardSquare(5,20, 'G');
	board->setBoardSquare(5,20, 'Y');
	while (isOn)
	{
		for (int y = 0; y < 1501; y += 50)
		{
			pRen->renderTetrisBlock(450,y,'g');
		}
		for (int y = 0; y < 1501; y += 50)
		{
			pRen->renderTetrisBlock(1000,y,'g');
		}
		board->drawBoard();
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
				blocx += 50;
			}
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a)
			{
				blocx -= 50;
			}
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_w)
			{
				blocy -= 50;
			}
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s)
			{
				blocy += 50;
			}
		}
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 30, 30, 30, 0);
		SDL_RenderClear(renderer);
		SDL_Delay(1);
	}
	delete board;
	delete pRen;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
