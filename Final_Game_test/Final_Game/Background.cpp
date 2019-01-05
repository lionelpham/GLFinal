#include "Background.h"
#define SPEED_BR 50


void Background::fixSize()
{
	m_texture.setRepeated(true);
	m_sprite.setTextureRect(IntRect(0, 0, WINDOWS_W * 100, WINDOWS_H * 100));
}

void Background::Update(float deltatime)
{
	m_sprite.setPosition(m_sprite.getPosition().x + SPEED_BR * deltatime*-1, m_sprite.getPosition().y);
}

Background::Background()
{
}


Background::~Background()
{
}
