#pragma once

#include <vector>


#include "Scene.h"
#include "Object.h"
#include "Enemy.h"
#include "Collision.h"
#include "Player.h"
#include "Background.h"
#include "CameraView.h"

#define ENEMY_COUNT 3
#define TEXTURE_ENEMY	"resources/enemy.png"
#define TEXTURE_PLAYER	"resources/player.png"
#define TEXTURE_BACKGROUND "resources/br.jpg"

using namespace std;

class GamePlayScene : public Scene
{
protected:
	CameraView camera;
	Background v_gameBackground;
	vector<Enemy*> v_gameEnemy;
	Player v_gamePlayer;
public:
	GamePlayScene();
	~GamePlayScene();
	void OnInit();
	void OnUpdate(float deltaTime);
	void OnRender(sf::RenderWindow &window);
	void OnExit();
};

