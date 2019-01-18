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
	case 6:
	case 7:
	case 11:
	{
		m_dir = 1;
		break;
	}
	case 2:
	case 4:
	case 8:
	case 13:
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
		this->setPos(WINDOWS_W / 3, 10);
		return;
	}
	case 2:
	{
		ObjectRender::Init(TEXTURE_STONE2);
		this->setPos(WINDOWS_W / 3, WINDOWS_H - m_texture.getSize().y - 10);
		return;
	}
	case 3:
	{
		ObjectRender::Init(TEXTURE_UFOBLUE);
		m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x*0.5, m_sprite.getTexture()->getSize().y*0.5));
		this->setPos(WINDOWS_W, 10 + m_texture.getSize().y*0.5);
		return;
	}
	case 4:
	{
		ObjectRender::Init(TEXTURE_UFOGREEN);
		m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x*0.5, m_sprite.getTexture()->getSize().y*0.5));
		this->setPos(WINDOWS_W + m_texture.getSize().x + 20, WINDOWS_H - m_texture.getSize().y*0.5 - 10);
		return;
	}
	case 5:
	{
		ObjectRender::Init(TEXTURE_PIG);
		this->setPos(WINDOWS_W / 3 * 5, WINDOWS_H / 2);
		m_sprite.setOrigin(sf::Vector2f(sf::Vector2f(m_sprite.getTexture()->getSize().x*0.5, m_sprite.getTexture()->getSize().y*0.5)));
		return;
	}
	case 6:
	{
		ObjectRender::Init(TEXTURE_ALIEN);
		this->setPos(WINDOWS_W / 3 * 7, 0);
		return;
	}
	case 7:
	case 8:
	{
		ObjectRender::Init(TEXTURE_LIGHTING);
		m_sprite.setScale(0.5, 0.5);
		this->setPos(WINDOWS_W / 3 * 9, 0);
		return;
	}
	case 9:
	{
		ObjectRender::Init(TEXTURE_BLADE1);
		this->setPos(WINDOWS_W / 3 * 11, 0);
		m_sprite.setScale(0.5, 0.5);
		return;
	}
	case 10:
	{
		ObjectRender::Init(TEXTURE_BLADE2);
		m_sprite.setScale(0.5, 0.5);
		this->setPos(WINDOWS_W / 3 * 11, 0);
		return;
	}
	case 11:
	{
		ObjectRender::Init(TEXTURE_SHURIKEN);
		m_sprite.setOrigin(sf::Vector2f(sf::Vector2f(m_sprite.getTexture()->getSize().x*0.5, m_sprite.getTexture()->getSize().y*0.5)));
		this->setPos(WINDOWS_W / 3 * 11 + 100, 0);
		return;
	}
	case 12:
	{
		ObjectRender::Init(TEXTURE_CURVE);
		this->setPos(WINDOWS_W / 3 * 13 + 40, WINDOWS_H / 2);
		m_sprite.setOrigin(sf::Vector2f(sf::Vector2f(m_sprite.getTexture()->getSize().x*0.5, m_sprite.getTexture()->getSize().y*0.5)));
		return;
	}
	case 13:
	{
		ObjectRender::Init(TEXTURE_ALIEN);
		this->setPos(WINDOWS_W / 3 * 15 + 300, 0);
		//m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x, m_sprite.getTexture()->getSize().y));

	}
	case 14:
	{
		ObjectRender::Init(TEXTURE_4KNIFE);
		this->setPos(WINDOWS_W / 3 * 17 + 50, WINDOWS_H / 2);
		m_sprite.setOrigin(sf::Vector2f(sf::Vector2f(m_sprite.getTexture()->getSize().x*0.5, m_sprite.getTexture()->getSize().y*0.5)));
		return;
	}

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
	case 11:
	{
		EnemyRotate(10);
		if (m_sprite.getPosition().y <= 0 + m_texture.getSize().y / 2 && m_dir != 1 || m_sprite.getPosition().y >= WINDOWS_H - m_texture.getSize().y / 2 && m_dir != -1)
		{
			m_dir = -m_dir;
		}
		m_sprite.move(0, NINJA_SPEED*dt*m_dir);
		break;
	}
	case 5:
	{
		EnemyRotate(2);
		break;
	}
	case 6:
	{
		m_sprite.move(0, ROCK_SPEED*dt*m_dir);
		if (m_sprite.getPosition().y >= WINDOWS_H)
		{
			m_sprite.setPosition(m_sprite.getPosition().x, 0);
		}
		break;
	}
	case 7:
	case 8:
	{
		if (m_sprite.getPosition().y <= 0 || m_sprite.getPosition().y >= WINDOWS_H - m_texture.getSize().y*0.5)
		{
			m_dir = -m_dir;
		}
		m_sprite.move(0, LIGHTING_SPEED*dt*m_dir);
		break;
	}
	case 12:
	{
		EnemyRotate(8);
		break;
	}
	case 13:
	{
		m_sprite.move(0, ROCK_SPEED*dt*m_dir);
		if (m_sprite.getPosition().y <= 0)
		{
			m_sprite.setPosition(WINDOWS_W / 3 * 15 + 300, WINDOWS_H);
		}
		break;
	}
	case 14:
	{
		EnemyRotate(3);
		break;
	}
	}


}

