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
	m_currentScene = new GamePlayScene();
	m_currentScene->OnInit();
}


void SceneManager::Update(float deltaTime)
{
	m_currentScene->OnUpdate(deltaTime);
}


void SceneManager::Render(sf::RenderWindow &window)
{
	m_currentScene->OnRender(window);
}


void SceneManager::SwitchScene(Scene* scene)
{
}