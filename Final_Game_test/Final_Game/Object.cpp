#include "Object.h"

Object::Object()
{
}


Object::~Object()
{
}


void Object::Init(const string path)
{
	m_texture.loadFromFile(path);
	m_sprite.setTexture(m_texture);
	switch (m_type)
	{
	case 1:
	{
		m_sprite.setPosition(300, 0);
		break;
	}
	case 2:
	{
		m_sprite.setPosition(300, WINDOWS_H - m_texture.getSize().y);
		break;
	}
	case 3:
	{
		m_sprite.setPosition(WINDOWS_W / 2, WINDOWS_H / 2);
		return;
	}
	}
}


void Object::Update(float deltaTime)
{
	
}


void Object::Render(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}
