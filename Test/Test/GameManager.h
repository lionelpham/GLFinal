#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#define TEXT "resource/player.png"
#define WINDOWS_W 900
#define WINDOWS_H 600
#define Distance 50

class GameManager
{
	static GameManager* s_Instance;
	Player player;
	Enemy enemy;
	Background br;
public:
	void Init();
	void Update(float dt);
	void Render(RenderWindow &window);
	void brMove();
	void brUpdate(float dt);
	static GameManager* getInstance()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new GameManager();
		}
		return s_Instance;
	}
	Vector2f dis()
	{
		return player.getPosition();
	}
	GameManager();
	~GameManager();
};

