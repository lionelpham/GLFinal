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
	
	Background* gameBackground = new Background();	//Init backgroud
	gameBackground->Init(TEXTURE_BACKGROUND);
	v_gameObject.push_back(gameBackground);			//Push to game object vector 

	camera.InitView();								//Init camera

	Player* gamePlayer = new Player();				//Init player	
	gamePlayer->Init(TEXTURE_PLAYER);
	v_gameObject.push_back(gamePlayer);				//Push to game object vector 
	
	//Init enemy 
	//Enemy will start from 2 in game object vector, 0 is background, 1 is player
	
	int typeEnemy[ENEMY_COUNT] = { 1,2,3 };			//Array type of Enemy
	for (int i = 0; i < ENEMY_COUNT; i++)	
	{
		Enemy* gameEnemy = new Enemy();
		gameEnemy->SetType(typeEnemy[i]);			//Set type for enemy
		gameEnemy->Init(TEXTURE_ENEMY);				//Init enemy
		v_gameObject.push_back(gameEnemy);			//Push to game object vector
	}
													
	//Init animation
	//Animation will start from last enemy in game object vector

	Animation* gameAnimation = new Animation();
	gameAnimation->Init(TEXTURE_ANIMATION_ELECTRIC);			//Init animation
	v_gameObject.push_back(gameAnimation);			//Push to game object vector

	//Test destroy animation
	/*Animation* destroy = new Animation();
	destroy->Init(TEXTURE_ANIMATION_DESTROY);
	destroy->setPos(WINDOWS_W / 2, WINDOWS_H / 2);
	v_gameObject.push_back(destroy);*/

}


void GamePlayScene::OnUpdate(float deltaTime)
{
	
	//First update background

	v_gameObject[0]->Update(deltaTime);

	//Update Enemy and check collision

	bool enemyCollision = false;					//Value check collision between 2 enemy
	for (int i = 2; i < v_gameObject.size(); i++)	//Check all of enemy
	{
		if (i < ENEMY_COUNT + 1)					//If enemy
		{
			enemyCollision = v_gameObject[i]->CheckCollision(v_gameObject[i + 1]->GetSprite());
			if (enemyCollision)						//If collision, set action for enemy
			{
				v_gameObject[i]->SetAction();
				v_gameObject[i + 1]->SetAction();
			}
		}
		v_gameObject[i]->Update(deltaTime);			//Update enemy
	}

	//Check collision between player and enemy
	bool playerCollision = false;
	for (int i = 2; i < v_gameObject.size(); i++)
	{
		playerCollision = v_gameObject[1]->CheckCollision(v_gameObject[i]->GetSprite());
		if (playerCollision)
		{
			Animation* destroy = new Animation();
			destroy->Init(TEXTURE_ANIMATION_DESTROY);
			destroy->setPos(v_gameObject[1]->getPos().x, v_gameObject[1]->getPos().y);
			//v_gameObject.push_back(destroy);
			v_gameObject.clear();
			v_gameObject.push_back(destroy);
			break;
		}
	}

	//phhviet code

	if (Mouse::isButtonPressed(Mouse::Left) && v_gameObject.size()>=2) 
	{
		v_gameObject[1]->Update(deltaTime);
		
	}
	//phhviet: đang bị bug chỗ này
	if (v_gameObject.size() >= 2)
	{
		float distance = (camera.getCenterPos().x - WINDOWS_W / 2) - v_gameObject[1]->getPos().x;
		if (distance < 0)
		{
			camera.UpdateView(deltaTime);
		}
	}
	
	
	//check when player has been destroyed
	/*for (int i = 0; i < v_gameEnemy.size(); i++)
	{
		if (v_gamePlayer.CheckCollision(v_gameEnemy[i]->GetSprite()))
		{
			Animation destroy;
			destroy.Init(TEXTURE_ANIMATION);
			m_animation = destroy;
		}
	}*/
}


void GamePlayScene::OnRender(sf::RenderWindow &window)
{

	//Camera & background must render first of all
	camera.SetView(window);

	//Render all member of vector game object

	for (int i = 0; i < v_gameObject.size(); i++)
	{
		v_gameObject[i]->Render(window);
	}

}


void GamePlayScene::OnExit()
{

	//Not ready

	std::cout << "Do nothing";

}
