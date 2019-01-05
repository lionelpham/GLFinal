#include "Enemy.h"

#define ENEMY_SPEED 200

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}


void Enemy::SetType(int type)
{
	Object::SetType(type);
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


void Enemy::SetAction()
{
	m_dir = -m_dir;
}


void Enemy::EnemyRotate()
{
	float angle = 100.0;
	m_sprite.rotate(angle);
}


void Enemy::Update(float dt)
{
	switch (m_type)
	{

	case 1:
	{

		if (m_sprite.getPosition().y <= 0)
		{
			m_dir = -m_dir;
		}
		m_sprite.move(0, ENEMY_SPEED*dt*m_dir);
		break;
	}

	case 2:
	{
		if (m_sprite.getPosition().y >= WINDOWS_H - m_texture.getSize().y)
		{
			m_dir = -m_dir;
		}
		m_sprite.move(0, ENEMY_SPEED*dt*m_dir);
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

