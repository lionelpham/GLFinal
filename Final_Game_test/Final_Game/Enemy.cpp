#include "Enemy.h"


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
	case 3:
	{
		m_dir = 1;
		break;
	}
	case 2:
	case 4:
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


void Enemy::EnemyRotate(float angle)
{
	m_sprite.rotate(angle);
}


void Enemy::Init(const string path)
{	
													
	//Set Position for enemy
	switch (m_type)
	{
	case 1:
	{
		ObjectRender::Init(TEXTURE_STONE1);
		this->setPos(WINDOWS_W/3, 10);
		return;
	}
	case 2:
	{
		ObjectRender::Init(TEXTURE_STONE2);
		this->setPos(WINDOWS_W/3, WINDOWS_H - m_texture.getSize().y - 10);
		return;
	}
	case 3:
	{
		ObjectRender::Init(TEXTURE_NINJA);
		m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x*0.5, m_sprite.getTexture()->getSize().y*0.5));
		this->setPos(WINDOWS_W, 10+m_texture.getSize().y*0.5);
		return;
	}
	case 4:
	{
		ObjectRender::Init(TEXTURE_NINJA);
		m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x*0.5, m_sprite.getTexture()->getSize().y*0.5));
		this->setPos(WINDOWS_W + m_texture.getSize().x, WINDOWS_H - m_texture.getSize().y*0.5 - 10);
		return;
	}
	case 5:
	{
		ObjectRender::Init(TEXTURE_PIG);
		this->setPos(WINDOWS_W / 3 * 5 + 50, WINDOWS_H / 2);
		m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x*0.5, WINDOWS_H/3 - 50/*m_sprite.getTexture()->getSize().y + 150*/));
		printf("%d", m_texture.getSize().y);
		return;
	}
	//case 6:
	//{
	//	ObjectRender::Init(TEXTURE_PIG);
	//	m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x*0.5, WINDOWS_H / 2 + m_texture.getSize().y / 2/*m_sprite.getTexture()->getSize().y + 150*/));
	//	this->setPos(WINDOWS_W / 3 * 5 +100, WINDOWS_H / 2);
	//}
	}
}


void Enemy::Update(float dt)
{
	switch (m_type)
	{

	case 1:
	case 2:
	{
		if (m_sprite.getPosition().y <= 0 || m_sprite.getPosition().y >= WINDOWS_H - m_texture.getSize().y)
		{
			m_dir = -m_dir;
		}
		m_sprite.move(0, ROCK_SPEED*dt*m_dir);
		break;
	}

	case 3:
	case 4:
	{
		EnemyRotate(10);
		if (m_sprite.getPosition().y <= 0 + m_texture.getSize().y/2 && m_dir != 1 || m_sprite.getPosition().y >= WINDOWS_H - m_texture.getSize().y/2 && m_dir != -1)
		{
			m_dir = -m_dir;
		}
		m_sprite.move(0, NINJA_SPEED*dt*m_dir);
		break;
	}
	case 5:
	case 6:
		EnemyRotate(2);
		break;
	}

}

