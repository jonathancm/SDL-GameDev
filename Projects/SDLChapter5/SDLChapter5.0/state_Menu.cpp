#include "state_Menu.h"
#include <stdio.h>
#include <string>

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	//Nothing for now
}

void MenuState::render()
{
	//Nothing for now
}

bool MenuState::onEnter()
{
	printf("Entering MenuState\n");
	return true;
}

bool MenuState::onExit()
{
	printf("Exiting MenuState\n");
	return false;
}
