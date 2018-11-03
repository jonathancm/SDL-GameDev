#ifndef __GAME__
#define __GAME__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <vector>

#include "InputHandler.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "GameStateMachine.h"
#include "state_Menu.h"
#include "state_Play.h"
//#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}

		return s_pInstance;
	}


	/* Simply set the ruinning variable to true */
	void init(){ m_bRunning = true; }

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit(){m_bRunning=false;};

	/* access the private running variable */
	bool running(){ return m_bRunning; }
	SDL_Renderer* getRenderer() const {return m_pRenderer;}

private:

	Game(){};
	~Game(){};

	static Game* s_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;

	bool m_bRunning;
	std::vector<GameObject*> m_gameObjects;

	GameStateMachine* m_pGameStateMachine;

};

typedef Game TheGame;

#endif /* defined(__GAME__) */