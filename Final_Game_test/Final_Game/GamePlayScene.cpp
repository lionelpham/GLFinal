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
		Object* gameObject = new Enemy();
		v_gameObjects.push_back(gameObject);
		v_gameObjects[i]->SetType(i + 1);
		v_gameObjects[i]->Init(TEXTURE_ENEMY);
	}

}


void GamePlayScene::OnUpdate(float deltaTime)
{
	bool objectCollision = false;
	for (int i = 0; i < v_gameObjects.size(); i++)
	{
		if (i < v_gameObjects.size() - 1)
		{
			objectCollision = v_gameObjects[i]->CheckCollision(v_gameObjects[i + 1]->GetSprite());
			if (objectCollision)
			{
				v_gameObjects[i]->SetAction();
				v_gameObjects[i + 1]->SetAction();
			}
		}
		v_gameObjects[i]->Update(deltaTime);
	}
}


void GamePlayScene::OnRender(sf::RenderWindow &window)
{
	for (int i = 0; i < v_gameObjects.size(); i++)
	{
		v_gameObjects[i]->Render(window);
	}
}


void GamePlayScene::OnExit()
{
	std::cout << "Do nothing";
}
