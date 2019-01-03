#include "pch.h"
#include "GameManager.h"


void GameManager::Init()
{
	player.Init(TEXT, 0, 300);
<<<<<<< HEAD
	enemy.Init(TEXT, 200,300);
=======
	br.Init("resource/br.jpg",0,300);
	
	
	//enemy.Init(TEXT, 100, 300);
>>>>>>> master
}

void GameManager::Update(float dt)
{
<<<<<<< HEAD
=======
	player.Update(dt);
	
	//enemy.Update(dt);
>>>>>>> master
}

void GameManager::Render(RenderWindow & window)
{
<<<<<<< HEAD
	player.Render(window);
	enemy.Render(window);
=======
	br.Render(window);
	player.Render(window);
	
	//enemy.Render(window);
}

void GameManager::brMove()
{
	br.Move(Vector2f(-1, 0));
}

void GameManager::brUpdate(float dt)
{
	br.Update(dt);
>>>>>>> master
}

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}
