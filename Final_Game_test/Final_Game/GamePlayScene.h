#pragma once

#include <vector>


#include "Scene.h"
#include "Object.h"
#include "Enemy.h"
#include "Collision.h"


#define ENEMY_COUNT 3
#define TEXTURE_ENEMY	"resources/enemy.png"

using namespace std;

class GamePlayScene : public Scene
{
protected:
	vector<Object*> v_gameObjects;
public:
	GamePlayScene();
	~GamePlayScene();
	void OnInit();
	void OnUpdate(float deltaTime);
	void OnRender(sf::RenderWindow &window);
	void OnExit();
};

