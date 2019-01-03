#include "pch.h"
#include "GameObjectRender.h"


void GameObjectRender::Init(const char * textureName, int x, int y)
{
	texture.loadFromFile(textureName);

	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.1,0.1);

	sprite.setPosition(x,y);
	//cout << "Ps" << getPositionX();
}

void GameObjectRender::Update(float dt)
{

}

void GameObjectRender::Render(RenderWindow & window)
{
	window.draw(sprite);
}

Vector2f GameObjectRender::getPosition()
{
	return sprite.getPosition();
}


GameObjectRender::GameObjectRender()
{
	
}


GameObjectRender::~GameObjectRender()
{
}
