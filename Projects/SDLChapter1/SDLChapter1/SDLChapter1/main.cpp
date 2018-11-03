#include <iostream>
#include <SDL.h>

SDL_Window* g_pWindow = NULL;
SDL_Renderer* g_pRenderer = NULL;

int main(int argc, char **argv){
	/* initialize SDL */
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		/*if succeeded create our own window*/
		g_pWindow = SDL_CreateWindow("Chapter 1: Setting up SDL",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480,
			SDL_WINDOW_SHOWN);

		/* if the window creation succeded create our renderer*/
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow,-1,0);

		}
	}
	else
	{
		return 1; //sdl could not initialize
	}

	/* set render to black */
	SDL_SetRenderDrawColor(g_pRenderer,0,0,0,255);

	/* clear the window to black */
	SDL_RenderClear(g_pRenderer);

	/* show the window */
	SDL_RenderPresent(g_pRenderer);

	/* wait before exiting */
	SDL_Delay(5000);

	/* clean up SDL */
	SDL_Quit();

	return 0;
}