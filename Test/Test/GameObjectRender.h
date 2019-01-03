#pragma once
#include "GameObject.h"
<<<<<<< HEAD

=======
#define WINDOWS_W 900
#define WINDOWS_H 600
#define FPS_LIMIT 60
#define SPEED 1000
>>>>>>> master
class GameObjectRender : public GameObject
{
protected:
	Texture texture;
	Sprite	sprite;
public:
	void Init(const char* textureName = "", int x = 0, int y = 0);
	void Update(float dt);
	void Render(RenderWindow &window);
<<<<<<< HEAD
=======
	Vector2f getPosition();
>>>>>>> master
	GameObjectRender();
	~GameObjectRender();
};

