#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Game.h"

int main(int argc, char **argv)
{

	std::cout << "Game initializing.\n";
	if(TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
	{
		std::cout << "Game init success.\n";
		while (TheGame::Instance()->running())
		{
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			SDL_Delay(10);
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