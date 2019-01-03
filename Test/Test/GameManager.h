#pragma once

#include "Player.h"
#include "Enemy.h"
<<<<<<< HEAD
#define TEXT "resource/player.png"
#define WINDOWS_W 900
#define WINDOWS_H 600
=======
#include "Background.h"
#define TEXT "resource/player.png"
#define WINDOWS_W 900
#define WINDOWS_H 600
#define Distance 50

>>>>>>> master
class GameManager
{
	static GameManager* s_Instance;
	Player player;
	Enemy enemy;
<<<<<<< HEAD
=======
	Background br;
>>>>>>> master
public:
	void Init();
	void Update(float dt);
	void Render(RenderWindow &window);
<<<<<<< HEAD
=======
	void brMove();
	void brUpdate(float dt);
>>>>>>> master
	static GameManager* getInstance()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new GameManager();
		}
		return s_Instance;
	}
<<<<<<< HEAD
=======
	Vector2f dis()
	{
		return player.getPosition();
	}
>>>>>>> master
	GameManager();
	~GameManager();
};

