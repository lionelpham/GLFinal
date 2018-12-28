#include "pch.h"
#include "GameObjectRender.h"


void GameObjectRender::Init(const char * textureName, int x, int y)
{
	
	texture.loadFromFile(textureName);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	
	//thu nhỏ về tỉ lệ bằng 1/10 ảnh gốc
	sprite.setScale(0.1, 0.1);
	sprite.setPosition(x,y - texture.getSize().y*0.1);
}

void GameObjectRender::Update(float dt)
{
	
}

void GameObjectRender::Render(RenderWindow & window)
{
	window.draw(sprite);
}

GameObjectRender::GameObjectRender()
{
	
}


GameObjectRender::~GameObjectRender()
{
}
