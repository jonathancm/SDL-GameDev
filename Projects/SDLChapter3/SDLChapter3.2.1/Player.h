#ifndef __PLAYER__
#define __PLAYER__

#include "SDLGameObject.h"

class Player : public SDLGameObject //inherit from GameObject
{
public:

	Player(const LoaderParams* pParams);
	~Player(){};

	virtual void draw();
	virtual void update();
	virtual void clean();

private:

};

class Enemy : public SDLGameObject //inherit from GameObject
{
public:

	Enemy(const LoaderParams* pParams);
	~Enemy(){};

	virtual void draw();
	virtual void update();
	virtual void clean();

private:

};

#endif /* defined(__PLAYER__) */