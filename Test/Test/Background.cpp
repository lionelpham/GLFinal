#include "pch.h"
#include "Background.h"



void Background::Init(const char * textureName, int x, int y)
{
	texture.loadFromFile(textureName);
	texture.setRepeated(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, WINDOWS_W*100, WINDOWS_H*100));
	
}

void Background::setSize()
{
	//cout << "size br: " << texture.getSize().x << " " << texture.getSize().y<<endl;
}

void Background::Update(float dt)
{
	sprite.setPosition(sprite.getPosition().x + 50 * dt*-1, sprite.getPosition().y);
}

void Background::Move(Vector2f f)
{
	sprite.move(f);
}

Background::Background()
{
}


Background::~Background()
{
}
