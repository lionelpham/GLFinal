#include "pch.h"
#include "GameManager.h"


void GameManager::Init()
{
	player.Init(TEXT, 0, 300);
	//br.Init("resource/br.jpg");
	//enemy.Init(TEXT, 100, 300);
}

void GameManager::Update(float dt, View&v)
{
	player.Update(dt,v);
	
	//	enemy.Update(dt);
}

void GameManager::Render(RenderWindow & window)
{

	player.Render(window);
	//br.Render(window);
	enemy.Render(window);
}

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}
