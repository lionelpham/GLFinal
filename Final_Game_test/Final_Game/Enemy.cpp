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
	ObjectRender::SetType(type);
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


void Enemy::Init(const string path)
{
	ObjectRender::Init(path);						//Init texture first
													
	//Set Position for enemy

	switch (m_type)
	{
	case 0: //test cloud
	{
		this->m_sprite.setTextureRect(IntRect(256, 128, 128, 128));
		m_sprite.setPosition(WINDOWS_W + 110, WINDOWS_H / 4 - 100);
		break;
	}
	case 1:
	{
		this->setPos(300, 10);
		break;
	}
	case 2:
	{
		this->setPos(300, WINDOWS_H - m_texture.getSize().y - 10);
		break;
	}
	case 3:
	{
		this->setPos(WINDOWS_W + 400, WINDOWS_H / 2);
		return;
	}
	}
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

