#ifndef __GAME__
#define __GAME__
#include "SDL.h"


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

	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	bool m_bRunning;
};

#endif /* defined(__GAME__) */