#include "GameStateMachine.h"
#include <stdio.h>

void GameStateMachine::pushState(GameState* pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
	//printf("File:%s\tLine:%u \n",__FILE__,__LINE__);
}

void GameStateMachine::popState()
{
	if(!m_gameStates.empty())
	{
		if(m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

void GameStateMachine::changeState(GameState* pState)
{
	if(!m_gameStates.empty())
	{
		if(m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return;
		}

		if(m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
		m_gameStates.push_back(pState);

		//initialise
		m_gameStates.back()->onEnter();
	}		
}

void GameStateMachine::update()
{
	if(!m_gameStates.empty())
		m_gameStates.back()->update();
}

void GameStateMachine::render()
{
	if(!m_gameStates.empty())
		m_gameStates.back()->render();
}