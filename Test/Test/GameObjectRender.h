#pragma once
#include "GameObject.h"

class GameObjectRender : public GameObject
{
protected:
	Texture texture;
	Sprite	sprite;
public:
	void Init(const char* textureName = "", int x = 0, int y = 0);
	void Update(float dt);
	void Render(RenderWindow &window);
	GameObjectRender();
	~GameObjectRender();
};

