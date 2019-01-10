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
	
	m_gameBackground.Init(TEXTURE_BACKGROUND);

	m_camera.InitView();								//Init camera
	
	m_gamePlayer.Init(TEXTURE_PLAYER);					//Init player
	

	//Distance between Enemy and Gem is WINDOWS_W/3
														//Init enemy
	int typeEnemy[ENEMY_COUNT] = { 1,2,3,4,5,6 };				//Array type of Enemy
	for (int i = 0; i < ENEMY_COUNT; i++)	
	{
		Enemy* gameEnemy = new Enemy();
		gameEnemy->SetType(typeEnemy[i]);				//Set type for enemy
		gameEnemy->Init("");							//Init enemy
		v_gameEnemy.push_back(gameEnemy);				//Push to game enemy vector
	}

														//Init gem
	int typeGem[GEM_COUNT] = { 3,2,1 };					//Array type of gem
	for (int i = 0; i < GEM_COUNT; i++)					
	{
		Gem* gameGem = new Gem();						
		gameGem->SetType(typeGem[i]);					//Set type for gem
		gameGem->Init("");								//Init gem
		v_gameGem.push_back(gameGem);					//Push to game gem vector
	}

	//Init Animation
	//int typeAniamtion[ANIMATION_COUNT] = { 1 };			//Array of type Animation
	//for (int i = 0; i < ANIMATION_COUNT; i++)
	//{
	//	Animation* gameAnimation = new Animation();
	//	gameAnimation->SetType(typeAniamtion[i]);		//Set type of animation
	//	gameAnimation->Init("");						//Init animation
	//	v_gameAnimation.push_back(gameAnimation);		//Push to game enemy vector
	//}
		
}


void GamePlayScene::OnUpdate(float deltaTime)
{
	
	//First update background

	m_gameBackground.Update(deltaTime);					

	//Update Enemy and check collision

	bool enemyCollision = false;						//Value check collision between 2 enemy
	for (int i = 0; i < v_gameEnemy.size(); i++)		//Check all of enemy
	{
		if (i < ENEMY_COUNT - 1)						//Check collision between 2 enemy
		{
			enemyCollision = v_gameEnemy[i]->CheckCollision(v_gameEnemy[i + 1]->GetSprite());
			if (enemyCollision)							//If collision, set action for enemy
			{
				v_gameEnemy[i]->SetAction();
				v_gameEnemy[i + 1]->SetAction();
			}
		}
		v_gameEnemy[i]->Update(deltaTime);				//Update enemy
	}

	//Check collision between player and enemy

	if (m_gamePlayer.checkAlive())						//If player still alive -> check collision
	{
		bool playerCollision = false;					//Value check collision between player and enemy
		for (int i = 0; i < v_gameEnemy.size(); i++)
		{
			playerCollision = m_gamePlayer.CheckCollision(v_gameEnemy[i]->GetSprite());
			if (playerCollision)						//If collision
			{
				m_gamePlayer.Die();						//Player dead
				Animation* destroy = new Animation();
				destroy->SetType(2);					//Add destroy animation
				destroy->Init("");	
				destroy->setPos(m_gamePlayer.getPos().x, m_gamePlayer.getPos().y - 30);
				v_gameAnimation.push_back(destroy);		//Set position of destroy animation in center of player's position
				break;
			}
		}
		
		/*for (int i = GEM_COUNT - 1; i >= 0; i--)
		{
			if (m_gamePlayer.CheckCollision(v_gameGem[i]->GetSprite()))
			{
				v_gameGem.pop_back();
			}
		}*/
	}

	//phhviet code

	if (Mouse::isButtonPressed(Mouse::Left)) 
	{
		m_gamePlayer.Update(deltaTime);
		
	}

	//phhviet: đang bị bug chỗ này

	float distance = (m_camera.getCenterPos().x - WINDOWS_W / 2) - m_gamePlayer.getPos().x;
	if (distance < 0)
	{
		m_camera.UpdateView(deltaTime);
	}
	
	for (int i = 0; i < v_gameAnimation.size(); i++)
	{
		v_gameAnimation[i]->Update(deltaTime);
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

	m_camera.SetView(window);							//Render camera
	m_gameBackground.Render(window);					//Render background

	for (int i = 0; i < v_gameEnemy.size(); i++)		//Render enemy
	{
		v_gameEnemy[i]->Render(window);
	}

	if (m_gamePlayer.checkAlive())
	{
		m_gamePlayer.Render(window);						//Render player
	}

	for (int i = 0; i < v_gameAnimation.size(); i++)	//Render animation
	{
		v_gameAnimation[i]->Render(window);
	}

	for (int i = GEM_COUNT-1; i >= 0; i--)
	{
		v_gameGem[i]->Render(window);	//Render gem
	}
}


void GamePlayScene::OnExit()
{

	//Not ready

	std::cout << "Do nothing";

}
