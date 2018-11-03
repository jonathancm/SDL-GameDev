#ifndef __ENEMY__
#define __ENEMY__

#include "SDLGameObject.h"

class Enemy : public SDLGameObject //inherit from GameObject
{
public:

	Enemy(const LoaderParams* pParams);

	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();
};

#endif /* defined(__ENEMY__) */