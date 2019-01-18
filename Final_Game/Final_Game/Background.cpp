#include "Background.h"
#define SPEED_BR 100


Background::Background()
{
}


Background::~Background()
{
}


void Background::fixSize()
{
	m_texture.setRepeated(true);
	m_sprite.setTextureRect(IntRect(0, 0, WINDOWS_W*1000, WINDOWS_H*1000 ));
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

void Background::setPosition(Vector2f f)
{
	m_sprite.setPosition(f);
}

void Background::fixScale()
{
	m_sprite.scale(0.5, 0.5);
	m_texture.setSmooth(true);
}


