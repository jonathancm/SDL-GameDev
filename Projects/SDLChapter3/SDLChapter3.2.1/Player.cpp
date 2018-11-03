#include "Player.h"

Player::Player(const LoaderParams* pParams): SDLGameObject(pParams)
{

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_x-=1;
	m_currentFrame = int((SDL_GetTicks() / 100) % 13);
}

void Player::clean()
{

}

/* Enemy */
Enemy::Enemy(const LoaderParams* pParams): SDLGameObject(pParams)
{

}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_x+=1;
	m_y+=1;
	m_currentFrame = int((SDL_GetTicks() / 100) % 13);
}

void Enemy::clean()
{

}