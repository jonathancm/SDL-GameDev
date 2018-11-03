#include "Game.h"
#include <iostream>
#include <string>
#include <stdio.h>

/* Static instance */
Game* Game::s_pInstance = 0;

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

	m_gameObjects.push_back(new Player(new LoaderParams(250, 250, 80, 95,"torizo")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(150, 150, 80, 95,"torizo")));

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->pushState(new MenuState());

	TheInputHandler::Instance()->initialiseJoysticks();

	std::cout << "Completed initialization\n";
	m_bRunning = true; // Start the main loop after good init

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear render to draw color

	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer); // Draw to screen
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TheInputHandler::Instance()->clean();
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();

	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::update()
{
	m_pGameStateMachine->update();
}