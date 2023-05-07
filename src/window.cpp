#include "gfx/window.h"

int window(void *data)
{
	extern bool running;
    std::cout << "Launching Tetris!\n";
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
	board->setBoardSquare(2,2,'G');
	board->setBoardSquare(2,1,'R');
	
	
	while (running)
	{		
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
			if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
			{
				running = false;
			}
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			{
				running = false;
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
		board->drawBoard();
		SDL_RenderPresent(renderer);
		pRen->clearScreen();
	}
	delete pRen;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}