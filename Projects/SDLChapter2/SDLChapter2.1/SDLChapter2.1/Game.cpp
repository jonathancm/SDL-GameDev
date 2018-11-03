#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	/* Init SDL */
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";

		/* Init window */
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0) //window init success
		{
			std::cout << "window creation success\n";

			/* Init renderer */
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				std::cout << "renderer creation successful\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "render init fail\n";
				return false;
			}
		}
		else
		{
			std::cout << "window creation fail\n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false;
	}

	std::cout << "init success\n";
	m_bRunning = true; // Start the main loop after good init

	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/variaSuit.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

	//m_sourceRectangle.w = 45;
	//m_sourceRectangle.h = 128;

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w = 45;
	m_destinationRectangle.h = m_sourceRectangle.h = 50;

	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	m_destinationRectangle.x = 100;
	m_destinationRectangle.y = 100;


	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear render to draw color

	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

	SDL_RenderPresent(m_pRenderer); // Draw to screen
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}