#include <iostream>

#include "GamePlayScene.h"


GamePlayScene::GamePlayScene()
{
	state = -1;
	Score = 0;
}


GamePlayScene::~GamePlayScene()
{
}

int GamePlayScene::getScore()
{
	return Score;
}

void GamePlayScene::setScore(int score)
{
}



void GamePlayScene::OnInit()
{
	//isBegin = true;

	MusicEff::getInstance()->pauseOverMusic();
	MusicEff::getInstance()->pausePreBrMusic();
	MusicEff::getInstance()->startBrMusic();


	m_gameBackground.Init(TEXTURE_BACKGROUND);

	m_camera.InitView();								//Init camera

	m_gamePlayer.Init(TEXTURE_PLAYER);					//Init player
	m_gamePlayer.setSize();

														//Distance between Enemy and Gem is WINDOWS_W/3
														//Init enemy
	int typeEnemy[ENEMY_COUNT] = { 1,2,3,4,5,6,6,6,8,7,8,7,3,9,11,10,5,12,1,2,6,6,6,14 };				//Array type of Enemy
	Vector2f posEnemy[ENEMY_COUNT] = { { 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,200 },{ 0,400 },{ WINDOWS_W / 3 * 9 - 50,400 },
	{ 0,10 },{ WINDOWS_W / 3 * 9 + 50,400 },{ WINDOWS_W / 3 * 9 + 100,10 },{ WINDOWS_W / 3 * 11 - 50,WINDOWS_H / 2 },
	{ 0,50 },{ 0,WINDOWS_H / 2 } ,{ 0,WINDOWS_H / 2 + 150 },{ WINDOWS_W / 3 * 13 + 40,0 },{ 0,0 },{ WINDOWS_W / 3 * 15 - 50,0 },
	{ WINDOWS_W / 3 * 15 - 50 ,0 },{ WINDOWS_W / 3 * 15 + 100,0 },{ WINDOWS_W / 3 * 15 + 100,200 },{ WINDOWS_W / 3 * 15 + 100,400 },{ 0,0 } };
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		Enemy* gameEnemy = new Enemy();
		gameEnemy->SetType(typeEnemy[i]);				//Set type for enemy
		gameEnemy->Init("");							//Init enemy
		gameEnemy->setPos(posEnemy[i].x, posEnemy[i].y);	//Set position for enemy
		v_gameEnemy.push_back(gameEnemy);				//Push to game enemy vector
	}

	//Init gem
	int typeGem[GEM_COUNT] = { 1,2,3,4,5,6,7,8,9,10 };	//Array type of gem
	for (int i = 0; i < GEM_COUNT; i++)
	{
		Gem* gameGem = new Gem();
		gameGem->SetType(typeGem[i]);					//Set type for gem
		gameGem->Init("");								//Init gem
		v_gameGem.push_back(gameGem);					//Push to game gem vector
	}


}

RenderWindow& GamePlayScene::getWindow(RenderWindow & window)
{
	return window;
}




static bool isMove = false;
static bool view = false;
void GamePlayScene::OnUpdate(float deltaTime, RenderWindow& window)
{
	if (m_gamePlayer.CheckAlive() == false && !(v_gameAnimation.empty()))
	{
		if (v_gameAnimation[0]->CheckAlive() == false)
		{
			Score = 0;
			state = 3;
			m_gamePlayer.setPosi();
			m_camera.setPosition(Vector2f(WINDOWS_W / 2, WINDOWS_H / 2));
			//sleep(microseconds(5000));
			return;
		}
	}
	//First update background

	m_gameBackground.Update(deltaTime);

	//Update Enemy and check collision

	bool enemyCollision = false;						//Value check collision between 2 enemy
	for (int i = 0; i < v_gameEnemy.size(); i++)		//Check all of enemy
	{
		if (i < v_gameEnemy.size() - 1)						//Check collision between 2 enemy
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
	float distance = 0;


	if (m_gamePlayer.CheckAlive() && !v_gameGem.empty())						//If player still alive -> check collision
	{

		int pos = m_gamePlayer.getPos().x;
		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			isMove = true;
		}
		float tmp = v_gameGem[0]->getPos().x;
		if (isMove == true)
		{
			if (v_gameAnimation.size() == 0)
			{
				Animation* run = new Animation();
				run->SetType(3);					
				run->Init("");
				run->setPos(m_gamePlayer.getPos().x, m_gamePlayer.getPos().y+10);
				v_gameAnimation.push_back(run);
			}
			if (v_gameAnimation.size() == 1)
			{
				if (!v_gameAnimation[0]->CheckAlive())
				{
					v_gameAnimation.pop_back();
				}
			}
			m_gamePlayer.Update(deltaTime, SPEED_PLAYER);
			if (m_gamePlayer.CheckCollision(v_gameGem[0]->GetSprite()) == true) {
				m_gamePlayer.Update(deltaTime, SPEED_AUTO);
				isMove = false;
				Score++;
				MusicEff::getInstance()->pauseBrMusic();
				MusicEff::getInstance()->startEated();
				MusicEff::getInstance()->startBrMusic();
				
			}
			distance = (m_camera.getCenterPos().x - WINDOWS_W / 2) - m_gamePlayer.getPos().x;
			//cout << distance << endl;
			if (-distance >= 0)
			{
				m_camera.UpdateView(deltaTime, SPEED_VIEW);
				view = true;
			}
		}
		else
		{
			distance = (m_camera.getCenterPos().x - WINDOWS_W / 2) - m_gamePlayer.getPos().x;
			if (-distance > 0 && view == true)
			{
				m_camera.UpdateView(deltaTime, SPEED_VIEW_NO_FLOW);
			}
			else
			{
				view = false;
				isMove = false;
			}

		}

		if (isMove == false && (m_gamePlayer.getPos().x < v_gameGem[0]->getPos().x))
		{
			m_gamePlayer.Update(deltaTime, 15);
		}
		//end Viet
		if (v_gameAnimation.size() == 1)
		{
			v_gameAnimation[0]->setPos(m_gamePlayer.getPos().x - 55, m_gamePlayer.getPos().y + 10);
		}


		bool playerCollision = false;					//Value check collision between player and enemy
		if (m_gamePlayer.CheckAlive())
		{
			for (int i = 0; i < v_gameEnemy.size(); i++)
			{
				playerCollision = m_gamePlayer.CheckCollision(v_gameEnemy[i]->GetSprite());
				if (playerCollision)						//If collision
				{
					MusicEff::getInstance()->pauseBrMusic();
					MusicEff::getInstance()->startDestroy();
					MusicEff::getInstance()->startBrMusic();
					m_gamePlayer.Die();						//Player dead
					v_gameAnimation.clear();
					Animation* destroy = new Animation();
					destroy->SetType(2);					//Add destroy animation
					destroy->Init("");
					destroy->setPos(m_gamePlayer.getPos().x, m_gamePlayer.getPos().y-35);
					v_gameAnimation.push_back(destroy);		//Set position of destroy animation in center of player's position
					break;
				}
			}
		}
		if (m_gamePlayer.CheckCollision(v_gameGem[0]->GetSprite()))
		{
			v_gameAnimation.erase(v_gameAnimation.begin());
			v_gameGem.erase(v_gameGem.begin());
			while (v_gameEnemy[0]->getPos().x < m_gamePlayer.getPos().x)
			{
				v_gameEnemy.erase(v_gameEnemy.begin());
			}
		}

	}

	
	for (int i = 0; i < v_gameAnimation.size(); i++)
	{
		v_gameAnimation[i]->Update(deltaTime);
	}

}

void GamePlayScene::OnRender(sf::RenderWindow &window)
{
	if (state == 3)
	{
		window.clear();
		v_gameEnemy.clear();
		v_gameGem.clear();
		v_gameAnimation.clear();
		//return;
	}
	//Camera & background must render first of all
	
	m_camera.SetView(window);							//Render camera
	m_gameBackground.Render(window);
	//Render background
	
	for (int i = 0; i < v_gameEnemy.size(); i++)		//Render enemy
	{
		v_gameEnemy[i]->Render(window);
	}

	if (m_gamePlayer.CheckAlive())
	{
		m_gamePlayer.Render(window);						//Render player
	}

	for (int i = 0; i < v_gameAnimation.size(); i++)	//Render animation
	{
		v_gameAnimation[i]->Render(window);
	}

	for (int i = 0; i < v_gameGem.size(); i++)
	{
		v_gameGem[i]->Render(window);	//Render gem
	}
}


int GamePlayScene::OnExit()
{
	return state;
}
