#include <iostream>

#include "GamePlayScene.h"

GamePlayScene::GamePlayScene()
{
}


GamePlayScene::~GamePlayScene()
{
}


void GamePlayScene::OnInit()
{
	v_gameBackground.Init(TEXTURE_BACKGROUND);
	v_gameBackground.fixSize();
	camera.InitView();
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		Enemy* enemy = new Enemy();
		v_gameEnemy.push_back(enemy);
		v_gameEnemy[i]->SetType(i + 1);
		v_gameEnemy[i]->Init(TEXTURE_ENEMY);
	}
	
	v_gamePlayer.Init(TEXTURE_PLAYER);
	v_gamePlayer.setPos(0, 300);
	v_gamePlayer.setSize();
}

static bool press = false;

void GamePlayScene::OnUpdate(float deltaTime)
{
	bool objectCollision = false;
	
	v_gameBackground.Update(deltaTime);

	for (int i = 0; i < v_gameEnemy.size(); i++)
	{
		if (i < v_gameEnemy.size() - 1)
		{
			objectCollision = v_gameEnemy[i]->CheckCollision(v_gameEnemy[i + 1]->GetSprite());
			if (objectCollision)
			{
				v_gameEnemy[i]->SetAction();
				v_gameEnemy[i + 1]->SetAction();
			}
		}
		v_gameEnemy[i]->Update(deltaTime);
	}
	
	float distance = 0;

		if (Mouse::isButtonPressed(Mouse::Left))
		{
				v_gamePlayer.Update(deltaTime, 1200);
				press = true;
		}
		else {
			//phhviet: đang bị bug chỗ này
			distance = (camera.getCenterPos().x - WINDOWS_W / 2) - v_gamePlayer.getPos().x;
			if (-distance - 20 > 0 && press == true)
				camera.UpdateView(deltaTime, 300);
			else
				press = false;

		}
	
	//100 vi tri tiep theo nó di chuyen cham toi
	if (press == false )
	{
		v_gamePlayer.Update(deltaTime, 5);
	}
	cout << "is press " << press <<endl;
	/*if (v_gamePlayer.getPos().x < 300 && press == true)
		v_gamePlayer.Update(deltaTime, 400);  && distance + 100>=0*/
}


void GamePlayScene::OnRender(sf::RenderWindow &window)
{
	//camera & background render phải đầu tiên
	camera.SetView(window);
	v_gameBackground.Render(window);

	for (int i = 0; i < v_gameEnemy.size(); i++)
	{
		v_gameEnemy[i]->Render(window);
	}

	v_gamePlayer.Render(window);
}


void GamePlayScene::OnExit()
{
	std::cout << "Do nothing";
}
