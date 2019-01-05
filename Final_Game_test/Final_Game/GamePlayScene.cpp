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
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		Enemy* enemy = new Enemy();
		v_gameEnemy.push_back(enemy);
		v_gameEnemy[i]->SetType(i + 1);
		v_gameEnemy[i]->Init(TEXTURE_ENEMY);
	}

}


void GamePlayScene::OnUpdate(float deltaTime)
{
	bool objectCollision = false;
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
}


void GamePlayScene::OnRender(sf::RenderWindow &window)
{
	for (int i = 0; i < v_gameEnemy.size(); i++)
	{
		v_gameEnemy[i]->Render(window);
	}
}


void GamePlayScene::OnExit()
{
	std::cout << "Do nothing";
}
