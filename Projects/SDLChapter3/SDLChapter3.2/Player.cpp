#include "Player.h"

Player::Player(const LoaderParams* pParams): SDLGameObject(pParams)
{

}

void Player::draw(SDL_Renderer* pRenderer)
{
	SDLGameObject::draw(pRenderer);
}

void Player::update()
{
	m_x-=1;
	m_currentFrame = int((SDL_GetTicks() / 100) % 13);
}

void Player::clean()
{

}