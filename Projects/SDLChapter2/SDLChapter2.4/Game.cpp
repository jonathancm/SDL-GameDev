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

	std::cout << "SDL init success\n";

	std::cout << "Loading textures\n";

	//m_textureManager.load("assets/animateTorizo.png", "torizo", m_pRenderer);
	if (!TheTextureManager::Instance()->load("assets/animateTorizo.png", "torizo", m_pRenderer))
		return false;

	std::cout << "Completed initialization\n";
	m_bRunning = true; // Start the main loop after good init

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear render to draw color


	//m_textureManager.draw("torizo", 250, 250, 80, 95, m_pRenderer);
	//m_textureManager.drawFrame("torizo", 80, 95, 80, 95, 1, m_currentFrame, m_pRenderer);

	TheTextureManager::Instance()->draw("torizo", 250, 250, 80, 95, m_pRenderer);

	TheTextureManager::Instance()->drawFrame("torizo", 80, 95, 80, 95, 1, m_currentFrame, m_pRenderer);

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

void Game::update()
{
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}