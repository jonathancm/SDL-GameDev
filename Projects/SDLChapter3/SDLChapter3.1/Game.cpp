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

	m_go = new GameObject();
	m_player = new Player();
	m_enemy = new Enemy();

	m_go->load(80, 95, 80, 95,"torizo");
	m_player->load(250, 250, 80, 95,"torizo");
	m_enemy->load(150, 150, 80, 95,"torizo");

	m_gameObjects.push_back(m_go);
	m_gameObjects.push_back(m_player);
	m_gameObjects.push_back(m_enemy);

	std::cout << "Completed initialization\n";
	m_bRunning = true; // Start the main loop after good init

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear render to draw color

	/* Loop through the objects and draw them */
	for(std::vector<GameObject*>::size_type i = 0; i !=m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
	}

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
	/* Loop through the objects and update them */
	for(std::vector<GameObject*>::size_type i = 0; i !=m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}