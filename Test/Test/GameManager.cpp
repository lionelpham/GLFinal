#include "pch.h"
#include "GameManager.h"


void GameManager::Init()
{
	player.Init(TEXT, 0, 300);
	enemy.Init(TEXT, 200,300);
}

void GameManager::Update(float dt)
{
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
