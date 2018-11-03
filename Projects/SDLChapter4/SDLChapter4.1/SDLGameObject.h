#ifndef __SDLGAMEOBJECT__
#define __SDLGAMEOBJECT__

//#include "Game.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "cartesianVector2D.h"

class SDLGameObject: public GameObject
{
public:

	SDLGameObject(const LoaderParams* pParams);

	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean(){};

protected:

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_width;
	int m_height;

	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;

};

#endif /* defined(__SDLGAMEOBJECT__) */
