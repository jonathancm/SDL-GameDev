#include "state_Play.h"
#include <stdio.h>
#include <string>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	//Nothing for now
}

void PlayState::render()
{
	//Nothing for now
}

bool PlayState::onEnter()
{
	printf("Entering PlayState\n");
	return true;
}

bool PlayState::onExit()
{
	printf("Exiting PlayState\n");
	return false;
}
