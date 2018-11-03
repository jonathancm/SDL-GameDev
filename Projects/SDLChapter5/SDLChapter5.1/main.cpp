#include <iostream>
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char **argv)
{
	Uint32 frameStart, frameTime;


	std::cout << "Game initializing.\n";
	if(TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
	{
		std::cout << "Game init success.\n";
		while (TheGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if(frameTime < DELAY_TIME)
			{
				SDL_Delay((int) (DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		std::cout << "Game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	std::cout << "Clean and exit to desktop.\n";
	TheGame::Instance()->clean();

	return 0;
}