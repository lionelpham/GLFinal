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
}


void ObjectRender::Update(float deltaTime)
{
}


void ObjectRender::Render(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}

