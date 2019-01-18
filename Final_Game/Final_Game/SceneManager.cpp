#include "SceneManager.h"



SceneManager::SceneManager()
{
	scene = 0;
	score = 0;
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


void SceneManager::Init(RenderWindow &window)
{
	if(scene ==0)
		m_currentScene = new MenuScene();
	//m_currentScene->getWindow(window);
	m_currentScene->OnInit();
}


void SceneManager::Update(float deltaTime,RenderWindow& window)
{
	score = m_currentScene->getScore();
	if (m_currentScene->OnExit() == 2 || m_currentScene->OnExit() == 3) {
		delete m_currentScene;
		m_currentScene = nullptr;
		return;
	}
	else
	{
		sleep(microseconds(5000));
		m_currentScene->OnUpdate(deltaTime,window);
	}
}


void SceneManager::Render(sf::RenderWindow &window)
{
	m_currentScene->OnRender(window);
	switch (m_currentScene->OnExit())
	{
	case 3:
		m_currentScene = new GameOverScene();
		m_currentScene->setScore(score);
		m_currentScene->OnInit();
		break;
	case 2:
		m_currentScene = new GamePlayScene();
		m_currentScene->OnInit();
		break;
	case 1:
		//option
		break;
	case 0:
		MusicEff::getInstance()->stopBrMusic();
		MusicEff::getInstance()->stopPreBrMusic();
		MusicEff::getInstance()->stopOverMusic();
		window.close();
		break;
	}
	
}


void SceneManager::SwitchScene(Scene* scene)
{
}