#include "SceneManager.h"



SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}


SceneManager* SceneManager::GetInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new SceneManager();
	}
	return s_instance;
}


void SceneManager::Init(const string path)
{
}


void SceneManager::Update(float deltaTime)
{
}


void SceneManager::Render(sf::RenderWindow &window)
{
}


void SceneManager::SwitchScene(Scene* scene)
{
}