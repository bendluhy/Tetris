
#include <iostream>
#include "gfx/window.h"
#include "SDL2/SDL_thread.h"
#include "SDL2/SDL.h"


//controls loop in window function
bool running = true;
int main()
{
	SDL_Thread *pThread = SDL_CreateThread(window, "Window", NULL);
	
	SDL_WaitThread(pThread, NULL);
	
	return 0;
}