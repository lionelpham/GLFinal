#include "pch.h"
#include "GameObjectRender.h"


void GameObjectRender::Init(const char * textureName, int x, int y)
{
	
	texture.loadFromFile(textureName);
	texture.setSmooth(true);
	
	sprite.setTexture(texture);
	
	
	
	sprite.setScale(0.1,0.1);
	
	sprite.setPosition(x,y-y*0.2/2);
	//cout << "Ps" << getPositionX();
}

void GameObjectRender::Update(float dt)
{

}

void GameObjectRender::Render(RenderWindow & window)
{
	window.draw(sprite);
}

float GameObjectRender::getPositionX()
{
	return sprite.getPosition().x;
}

float GameObjectRender::getPositionY()
{
	return sprite.getPosition().y;
}

GameObjectRender::GameObjectRender()
{
	
}


GameObjectRender::~GameObjectRender()
{
}
