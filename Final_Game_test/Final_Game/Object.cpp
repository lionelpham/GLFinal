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
	if (m_type == 1)
	{
		m_sprite.setPosition(300, 0);
	}
	else
	{
		m_sprite.setPosition(300, WINDOWS_H - m_texture.getSize().y);
	}
}


void Object::Update(float deltaTime)
{
	
}


void Object::Render(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}
