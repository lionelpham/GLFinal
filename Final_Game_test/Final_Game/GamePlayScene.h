#pragma once

#include <vector>


#include "Scene.h"
#include "Object.h"
#include "Enemy.h"
#include "Collision.h"
#include "Player.h"
#include "Background.h"
#include "CameraView.h"
#include "Animation.h"
#include "Gem.h"


#define ENEMY_COUNT 6
#define GEM_COUNT 3
#define ANIMATION_COUNT 1
#define TEXTURE_PLAYER	"resources/player.png"
#define TEXTURE_BACKGROUND "resources/br.jpg"
#define TEXTURE_CLOUD "resources/cloud.png"

using namespace std;

class GamePlayScene : public Scene
{
protected:
	CameraView m_camera;
	Background m_gameBackground;
	vector<Enemy*> v_gameEnemy;
	vector<Gem*> v_gameGem;
	Player m_gamePlayer;
	vector<Animation*> v_gameAnimation;

public:
	GamePlayScene();
	~GamePlayScene();
	void OnInit();
	void OnUpdate(float deltaTime);
	void OnRender(sf::RenderWindow &window);
	void OnExit();
};

