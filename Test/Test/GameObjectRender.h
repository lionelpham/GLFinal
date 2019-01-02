#pragma once
#include "GameObject.h"
#define WINDOWS_W 900
#define WINDOWS_H 600
#define FPS_LIMIT 60
#define SPEED 1000
class GameObjectRender : public GameObject
{
protected:
	Texture texture;
	Sprite	sprite;
public:
	void Init(const char* textureName = "", int x = 0, int y = 0);
	void Update(float dt, View  &v);
	void Render(RenderWindow &window);
	float getPositionX();
	float getPositionY();
	GameObjectRender();
	~GameObjectRender();
};

