#include "renderer.h"



Renderer::Renderer(SDL_Renderer* pRen)
{
	renderer = pRen;
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
};
void Renderer::drawSquare(int x, int y, int h, int w, int r, int g, int b)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 0);
	for (int cx = x; cx < x + w + 1; cx++)
	{ 
		for (int cy = y; cy < y + h; cy++)
		{
			SDL_RenderDrawPoint(renderer, cx, cy);
		}
	}
};
void Renderer::renderTetrimino(int x, int y, char block)
{
	switch(block)
	{
		case 'I':
			renderTetrisBlock(x,y,'C');
			renderTetrisBlock(x + blocksize,y,'C');
			renderTetrisBlock(x + blocksize * 2,y,'C');
			renderTetrisBlock(x + blocksize * 3,y,'C');
			break;
		case 'J':
			renderTetrisBlock(x,y,'B');
			renderTetrisBlock(x,y + blocksize,'B');
			renderTetrisBlock(x + blocksize,y + blocksize,'B');
			renderTetrisBlock(x + (blocksize * 2),y + blocksize,'B');
			break;
		case 'L':
			renderTetrisBlock(x + (blocksize * 2),y,'O');
			renderTetrisBlock(x,y + blocksize,'O');
			renderTetrisBlock(x + blocksize,y + blocksize,'O');
			renderTetrisBlock(x + (blocksize * 2),y + blocksize,'O');
			break;
		case 'O':
			renderTetrisBlock(x,y,'Y');
			renderTetrisBlock(x +blocksize, y,'Y');
			renderTetrisBlock(x,y + blocksize,'Y');
			renderTetrisBlock(x + blocksize,y + blocksize,'Y');
			break;
		case 'S':
			renderTetrisBlock(x + blocksize,y,'G');
			renderTetrisBlock(x +(blocksize * 2), y,'G');
			renderTetrisBlock(x,y + blocksize,'G');
			renderTetrisBlock(x + blocksize,y + blocksize,'G');
			break;
		case 'Z':
			renderTetrisBlock(x,y,'R');
			renderTetrisBlock(x + blocksize, y,'R');
			renderTetrisBlock(x + blocksize,y + blocksize,'R');
			renderTetrisBlock(x + (blocksize * 2),y + blocksize,'R');
			break;
		case 'T':
			renderTetrisBlock(x+ blocksize,y,'P');
			renderTetrisBlock(x, y + blocksize,'P');
			renderTetrisBlock(x + blocksize,y + blocksize,'P');
			renderTetrisBlock(x + (blocksize * 2),y + blocksize,'P');
		default:
			std::cout << "Not matching tetrimino for character" << std::endl;	
	}
}
void Renderer::clearScreen()
{
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 0);
	SDL_RenderClear(renderer);
}
void Renderer::renderTetrisBlock(int x, int y, char c)
{
	// render base square
		//Set base block color based on char
	switch (c)
	{
	case 'R':
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
			break;
	case 'Y':
			SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
			break;
	case 'G':
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
			break;
	case 'B':
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
			break;
	case 'C':
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
			break;
	case 'P':
			SDL_SetRenderDrawColor(renderer, 128, 0, 128, 0);
			break;
	case 'O':
			SDL_SetRenderDrawColor(renderer, 255, 127, 0, 0);
			break;
	case 'g':
			SDL_SetRenderDrawColor(renderer, 127, 127, 127, 0);
			break;
	default:
			throw std::invalid_argument("Character didn't match color");
	};
		for (int cx = x; cx < x + 50; cx++)
		{
			for (int cy = y; cy < y + 50; cy++)
			{
				SDL_RenderDrawPoint(renderer, cx, cy);
			}
		}
		//Color settings for shadow 
		switch (c)
		{
		case 'R':
			SDL_SetRenderDrawColor(renderer, 193, 0, 0, 0);
			break;
		case 'Y':
			SDL_SetRenderDrawColor(renderer, 191, 191, 0, 0);
			break;
		case 'G':
			SDL_SetRenderDrawColor(renderer, 0, 192, 0, 0);
			break;
		case 'B':
			SDL_SetRenderDrawColor(renderer, 0, 0, 191, 0);
			break;
		case 'C':
			SDL_SetRenderDrawColor(renderer, 0, 191, 191, 0);
			break;
		case 'P':
			SDL_SetRenderDrawColor(renderer, 63, 0, 63, 0);
			break;
		case 'O':
			SDL_SetRenderDrawColor(renderer, 191, 92, 0, 0);
			break;
		case 'g':
			SDL_SetRenderDrawColor(renderer, 61, 61, 61, 0);
			break;
		default:
			throw std::invalid_argument("Character didn't match color");
		};

		// render vertical shadow line
		
		for (int cx = x; cx < x + 5; cx++)
		{
			for (int cy = y; cy < y + 50; cy++)
			{
				SDL_RenderDrawPoint(renderer, cx, cy);
			}
		}

		// render horizontal shadow line
		for (int cx = x; cx < x + 50; cx++)
		{
			for (int cy = y + 46; cy < y + 50; cy++)
			{
				SDL_RenderDrawPoint(renderer, cx, cy);
			}
		}

		//Color setting for highlight lines
		switch (c)
		{
		case 'R':
			SDL_SetRenderDrawColor(renderer, 255, 63, 63, 0);
			break;
		case 'Y':
			SDL_SetRenderDrawColor(renderer, 255, 255, 63, 0);
			break;
		case 'G':
			SDL_SetRenderDrawColor(renderer, 63, 255, 63, 0);
			break;
		case 'B':
			SDL_SetRenderDrawColor(renderer, 63, 63, 255, 0);
			break;
		case 'C':
			SDL_SetRenderDrawColor(renderer, 63, 255, 255, 0);
			break;
		case 'P':
			SDL_SetRenderDrawColor(renderer, 191, 0, 191, 0);
			break;
		case 'O':
			SDL_SetRenderDrawColor(renderer, 255, 156, 63, 0);
			break;
		case 'g':
			SDL_SetRenderDrawColor(renderer, 188, 188, 188, 0);
			break;
		default:
			throw std::invalid_argument("Character didn't match color");
		};
		// render horizontal hightlight line
		for (int cx = x; cx < x + 50; cx++)
		{
			for (int cy = y; cy < y + 4; cy++)
			{
				SDL_RenderDrawPoint(renderer, cx, cy);
			}
		}
		// render vertical highlight line
		for (int cx = x + 46; cx < x + 50; cx++)
		{
			for (int cy = y; cy < y + 50; cy++)
			{
				SDL_RenderDrawPoint(renderer, cx, cy);
			}
		}
		// render corners
		// render topright corner
		switch (c)
		{
		case 'R':
			SDL_SetRenderDrawColor(renderer, 193, 0, 0, 0);
			break;
		case 'Y':
			SDL_SetRenderDrawColor(renderer, 191, 191, 0, 0);
			break;
		case 'G':
			SDL_SetRenderDrawColor(renderer, 0, 192, 0, 0);
			break;
		case 'B':
			SDL_SetRenderDrawColor(renderer, 0, 0, 191, 0);
			break;
		case 'C':
			SDL_SetRenderDrawColor(renderer, 0, 191, 191, 0);
			break;
		case 'P':
			SDL_SetRenderDrawColor(renderer, 63, 0, 63, 0);
			break;
		case 'O':
			SDL_SetRenderDrawColor(renderer, 191, 92, 0, 0);
			break;
		case 'g':
			SDL_SetRenderDrawColor(renderer, 61, 61, 61, 0);
			break;
		default:
			throw std::invalid_argument("Character didn't match color");
		};
		SDL_RenderDrawPoint(renderer, x, y);

		SDL_RenderDrawPoint(renderer, x, y + 1);
		SDL_RenderDrawPoint(renderer, x + 1, y + 1);

		SDL_RenderDrawPoint(renderer, x, y + 2);
		SDL_RenderDrawPoint(renderer, x + 1, y + 2);
		SDL_RenderDrawPoint(renderer, x + 2, y + 2);

		SDL_RenderDrawPoint(renderer, x, y + 3);
		SDL_RenderDrawPoint(renderer, x + 1, y + 3);
		SDL_RenderDrawPoint(renderer, x + 2, y + 3);
		SDL_RenderDrawPoint(renderer, x + 3, y + 3);

		// Render bottom left
		SDL_RenderDrawPoint(renderer, x + 46, y + 46);

		SDL_RenderDrawPoint(renderer, x + 46, y + 47);
		SDL_RenderDrawPoint(renderer, x + 47, y + 47);

		SDL_RenderDrawPoint(renderer, x + 46, y + 48);
		SDL_RenderDrawPoint(renderer, x + 47, y + 48);
		SDL_RenderDrawPoint(renderer, x + 48, y + 48);

		SDL_RenderDrawPoint(renderer, x + 46, y + 49);
		SDL_RenderDrawPoint(renderer, x + 47, y + 49);
		SDL_RenderDrawPoint(renderer, x + 48, y + 49);
		SDL_RenderDrawPoint(renderer, x + 49, y + 49);
};
