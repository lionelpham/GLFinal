#include "pch.h"
#include "GameManager.h"


void GameManager::Init()
{
	player.Init(TEXT, 0, 300);
	enemy.Init(TEXT, 100,300);
}

void GameManager::Update(float dt)
{
	player.Update(dt);
	enemy.Update(dt);
}

void GameManager::Render(RenderWindow & window)
{
	player.Render(window);
	enemy.Render(window);
}

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}
