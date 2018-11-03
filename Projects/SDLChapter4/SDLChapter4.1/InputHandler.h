#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__

#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <vector>
#include <iostream>
#include "Game.h"
#include "cartesianVector2D.h"

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void initialiseJoysticks();
	bool joysticksInitialised()
	{
		return m_bJoysticksInitialised;
	}

	void update();
	void clean();

	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	bool getButtonState(int joy, int buttonNumber)
	{
		return m_buttonStates[joy][buttonNumber];
	}

private:
	InputHandler();
	~InputHandler(){};

	static InputHandler* s_pInstance;

	bool m_bJoysticksInitialised;
	const int m_joystickDeadZone=10000;

	/* Vectors storing Controller data */
	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::pair<Vector2D*, Vector2D*> > m_joystickValues;
	std::vector<std::vector<bool> > m_buttonStates;

	/* Mouse data */
	std::vector<bool> m_mouseButtonStates;


};

typedef InputHandler TheInputHandler;

#endif /* defined(__INPUTHANDLER__) */