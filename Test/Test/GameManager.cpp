#include "pch.h"
#include "GameManager.h"


void GameManager::Init()
{
	player.Init(TEXT, 0, 300);
	br.Init("resource/br.jpg",0,300);
	
	
	enemy.Init(TEXT, 200, 300);
}

void GameManager::Update(float dt)
{
	player.Update(dt);
	//check collision
	enemy.Update(dt);
}

void GameManager::Render(RenderWindow & window)
{
	br.Render(window);
	player.Render(window);
	
	enemy.Render(window);
}

void GameManager::brMove()
{
	br.Move(Vector2f(-1, 0));
}

void GameManager::brUpdate(float dt)
{
	br.Update(dt);
}

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}
