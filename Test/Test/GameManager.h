#pragma once

#include "Player.h"
#include "Enemy.h"
#define TEXT "resource/player.png"
#define WINDOWS_W 900
#define WINDOWS_H 600
#define Distance 50
class GameManager
{
	static GameManager* s_Instance;
	Player player;
	Enemy enemy;
public:
	void Init();
	void Update(float dt);
	void Render(RenderWindow &window);
	static GameManager* getInstance()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new GameManager();
		}
		return s_Instance;
	}
	GameManager();
	~GameManager();
};

