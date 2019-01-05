#include "ObjectRender.h"


ObjectRender::ObjectRender()
{
}


ObjectRender::~ObjectRender()
{
}


void ObjectRender::SetType(int type)
{
	m_type = type;
}


sf::Sprite ObjectRender::GetSprite()
{
	return m_sprite;
}


void ObjectRender::SetAction()
{
}

bool ObjectRender::CheckCollision(sf::Sprite sprite)
{
	return (Collision::PixelPerfectTest(this->GetSprite(), sprite));
}


void ObjectRender::Init(const string path)
{
	Collision::CreateTextureAndBitmask(m_texture, path);
	m_sprite.setTexture(m_texture);
	switch (m_type)
	{
	case 1:
	{
		m_sprite.setPosition(300, 10);
		break;
	}
	case 2:
	{
		m_sprite.setPosition(300, WINDOWS_H - m_texture.getSize().y - 10);
		break;
	}
	case 3:
	{
		m_sprite.setPosition(WINDOWS_W / 2, WINDOWS_H / 2);
		return;
	}
	}
}


void ObjectRender::Update(float deltaTime)
{
}


void ObjectRender::Render(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}

