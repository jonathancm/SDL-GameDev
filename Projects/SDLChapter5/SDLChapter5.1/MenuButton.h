#ifndef __MENUBUTTON__
#define __MENUBUTTON__

#include "SDLGameObject.h"

class MenuButton: public SDLGameObject
{
public:

	MenuButton(const LoaderParams* pParams);

	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();

private:

	enum button_states
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

};

#endif /* defined(__MENUBUTTON__) */
