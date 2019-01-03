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
		v_gameObjects[i]->Init(TEXTURE_ENEMY);
		v_gameObjects[i]->setType(i + 1);
	}

}


void GamePlayScene::OnUpdate(float deltaTime)
{
	for (int i = 0; i < v_gameObjects.size(); i++)
	{
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
	cout << "Do nothing";
}
