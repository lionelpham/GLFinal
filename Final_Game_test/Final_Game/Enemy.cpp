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
	switch (m_type)
	{
	case 1:
	{
		m_dir = 1;
		break;
	}
	case 2:
	{
		m_dir = -1;
		break;
	}
	}
}

void Enemy::EnemyUp(float &posy)
{
	if (posy >= WINDOWS_H - m_texture.getSize().y || posy <= WINDOWS_H / 2)
	{
		m_dir = -m_dir;
	}
}

void Enemy::EnemyDown(float &posy)
{
	if (posy <= 0 || posy >= WINDOWS_H / 2 - m_texture.getSize().y)
	{
		m_dir = -m_dir;
	}
}


void Enemy::EnemyRotate()
{
	float angle = 3.0;
	m_sprite.rotate(angle);
}

void Enemy::Update(float dt)
{
	auto pos = m_sprite.getPosition();
	if (m_type == 2)
	{
		pos.y += ENEMY_SPEED * dt*m_dir;
		EnemyUp(pos.y);
		m_sprite.setPosition(pos);
	}
	switch (m_type)
	{
		case 1:
		{
			pos.y += ENEMY_SPEED * dt*m_dir;
			EnemyDown(pos.y);
			m_sprite.setPosition(pos);
			break;
		}
		case 3:
		{
			m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x*0.5, m_sprite.getTexture()->getSize().y*0.5));
			EnemyRotate();
			break;
		}
	}
	
}

