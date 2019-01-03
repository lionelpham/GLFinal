#include "pch.h"
#include "GameObjectRender.h"


void GameObjectRender::Init(const char * textureName, int x, int y)
{
<<<<<<< HEAD
	
	texture.loadFromFile(textureName);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	
	//thu nhỏ về tỉ lệ bằng 1/10 ảnh gốc
	sprite.setScale(0.1, 0.1);
	sprite.setPosition(x,y - texture.getSize().y*0.1);
=======
	texture.loadFromFile(textureName);

	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.1,0.1);

	sprite.setPosition(x,y);
	//cout << "Ps" << getPositionX();
>>>>>>> master
}

void GameObjectRender::Update(float dt)
{
<<<<<<< HEAD
=======

>>>>>>> master
}

void GameObjectRender::Render(RenderWindow & window)
{
	window.draw(sprite);
}

<<<<<<< HEAD
=======
Vector2f GameObjectRender::getPosition()
{
	return sprite.getPosition();
}


>>>>>>> master
GameObjectRender::GameObjectRender()
{
	
}


GameObjectRender::~GameObjectRender()
{
}
