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
#include "MusicEff.h"
#define ENEMY_COUNT 24
#define GEM_COUNT 10
#define ANIMATION_COUNT 1
#define TEXTURE_PLAYER	"resources/player.png"
#define TEXTURE_BACKGROUND "resources/bg.png"
#define TEXTURE_CLOUD "resources/cloud.png"
#define FONT "resources/Cucho.otf"

#define SPEED_PLAYER 500
#define SPEED_AUTO 15
#define SPEED_VIEW 700
#define SPEED_VIEW_NO_FLOW 700

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
	Font m_Font;
	Text m_text;
	int state;
	int Score;
public:
	GamePlayScene();
	~GamePlayScene();
	int getScore();
	void setScore(int score);
	void OnInit();
	RenderWindow& getWindow(RenderWindow &window);
	void OnUpdate(float deltaTime, RenderWindow& window);
	void OnRender(sf::RenderWindow &window);
	int OnExit();
};

