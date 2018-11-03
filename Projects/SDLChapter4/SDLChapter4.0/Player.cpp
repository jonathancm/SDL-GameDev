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
	m_currentFrame = int((SDL_GetTicks() / 100) % 13);

	m_acceleration.setX(-0.5);

	SDLGameObject::update();
}

void Player::clean()
{

}