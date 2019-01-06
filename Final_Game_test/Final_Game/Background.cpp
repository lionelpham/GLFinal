#include "Background.h"
#define SPEED_BR 50


Background::Background()
{
}


Background::~Background()
{
}


void Background::fixSize()
{
	m_texture.setRepeated(true);
	m_sprite.setTextureRect(IntRect(0, 0, WINDOWS_W * 100, WINDOWS_H * 100));
}


void Background::Init(const string path)
{
	ObjectRender::Init(path);
	fixSize();
}


void Background::Update(float deltatime)
{
	m_sprite.setPosition(m_sprite.getPosition().x + SPEED_BR * deltatime*-1, m_sprite.getPosition().y);
}


