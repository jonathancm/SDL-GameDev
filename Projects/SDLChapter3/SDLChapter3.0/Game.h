#ifndef __GAME__
#define __GAME__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"

class Game
{
public:

	Game(){}
	~Game(){}

	/* Simply set the ruinning variable to true */
	void init(){ m_bRunning = true; }

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();

	/* access the private running variable */
	bool running(){ return m_bRunning; }

private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;

	/* The following line is not needed anymore. See singleton */
	//TextureManager m_textureManager;

	bool m_bRunning;

	GameObject m_go;
	Player m_player;

};

#endif /* defined(__GAME__) */