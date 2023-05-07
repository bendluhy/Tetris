#include "gfx/window.h"
#include "board.h"
#include "renderer.h"
int window(void *data)
{
	extern bool running;
	extern Board *pBoard;
	extern Renderer *pRen;
	extern SDL_Window *win;
	extern SDL_Renderer *pSRen;
    std::cout << "Launching Tetris!\n";
	
		
	while (running)
	{		
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
			if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(win))
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
		pBoard->drawBoard();
		SDL_RenderPresent(pSRen);
		pRen->clearScreen();
	}
	delete pRen;
	SDL_DestroyRenderer(pSRen);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}