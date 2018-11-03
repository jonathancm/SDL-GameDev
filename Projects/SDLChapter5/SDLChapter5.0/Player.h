#ifndef __PLAYER__
#define __PLAYER__

#include "SDLGameObject.h"
#include "cartesianVector2D.h"
#include "InputHandler.h"
//#include "LoaderParams.h"

class Player : public SDLGameObject //inherit from GameObject
{
public:

	Player(const LoaderParams* pParams);

	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();
private:

	void handleInput();
};

#endif /* defined(__PLAYER__) */