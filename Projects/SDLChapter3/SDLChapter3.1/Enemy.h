#ifndef __ENEMY__
#define __ENEMY__

#include "GameObject.h"

class Enemy : public GameObject //inherit from GameObject
{
public:

	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean(){};
};

#endif /* defined(__ENEMY__) */