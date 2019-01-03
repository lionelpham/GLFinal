#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}


void Object::Init(const string path, int x, int y)
{
	m_texture.loadFromFile(path);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(x, y);
}


void Object::Update(float deltaTime)
{
}


void Object::Render(sf::RenderWindow &window)
{
}
