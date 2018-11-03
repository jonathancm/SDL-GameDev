#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__

#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <vector>
#include <iostream>
#include "Game.h"
#include "cartesianVector2D.h"

enum mouse_buttons
{
	LEFT=0,
	MIDDLE=1,
	RIGHT=2
};

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

	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

	Vector2D* getMousePosition()
	{
		return m_mousePosition;
	}

	bool isKeyDown(SDL_Scancode key);

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
	Vector2D* m_mousePosition;
	std::vector<bool> m_mouseButtonStates;

	/* Keyboard data */
	const Uint8* m_keystates;


	/* Functions to handle inputs */

	/* Keyboard events */
	void onKeyDown();
	void onKeyUp();

	/* mouse events */
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	/* joystick events */
	void onJoystickAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);

};

typedef InputHandler TheInputHandler;

#endif /* defined(__INPUTHANDLER__) */