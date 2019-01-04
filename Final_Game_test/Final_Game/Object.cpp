#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}


void Object::SetType(int type)
{
	m_type = type;

}


sf::Sprite Object::GetSprite()
{
	return m_sprite;
}


bool Object::CheckCollision(sf::Sprite sprite)
{
	return (Collision::PixelPerfectTest(this->GetSprite(), sprite));
}


void Object::SetAction()
{

}


void Object::Init(const string path)
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
		m_sprite.setPosition(300, WINDOWS_H - m_texture.getSize().y-10);
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
