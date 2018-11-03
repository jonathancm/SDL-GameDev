#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams): SDLGameObject(pParams)
{

}

void Enemy::draw(SDL_Renderer* pRenderer)
{
	SDLGameObject::draw(pRenderer);
}

void Enemy::update()
{
	m_position.setX(m_position.getX() + 1);
	m_position.setY(m_position.getY() + 1);
	m_currentFrame = int((SDL_GetTicks() / 100) % 13);
}

void Enemy::clean()
{

}