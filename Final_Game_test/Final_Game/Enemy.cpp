#include "Enemy.h"

#define ENEMY_SPEED 200

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}


void Enemy::setType(int type)
{
	m_type = type;
	m_dir = type;
}
void Enemy::Update(float dt)
{

	auto pos = m_sprite.getPosition();
	if (pos.y >= WINDOWS_H - m_texture.getSize().y || pos.y <= 0)
	{
		m_dir = -m_dir;
	}
	if (m_type == 1 && pos.y >= WINDOWS_H / 2 - m_texture.getSize().y)
	{
		m_dir = -m_dir;
	}
	if (m_type == -1 && pos.y <= WINDOWS_H / 2)
	{
		m_dir = -m_dir;
	}

	pos.y += ENEMY_SPEED * dt*m_dir;
	m_sprite.setPosition(pos);
}

