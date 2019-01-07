#include "Player.h"

#define SPEED 1600

void Player::setPos(float x, float y)
{
	m_sprite.setPosition(x, y);
}

Vector2f Player::getPos()
{
	return m_sprite.getPosition();
}

void Player::setSize()
{
	m_sprite.setScale(0.1, 0.1);
}

void Player::Update(float dt, int speed)
{
	m_sprite.setPosition(m_sprite.getPosition().x + 2 * speed*dt, m_sprite.getPosition().y);
}

Player::Player()
{
	m_isAlive = true;
}


Player::~Player()
{
}
