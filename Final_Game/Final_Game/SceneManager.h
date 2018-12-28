#pragma once

#include "Scene.h"

class SceneManager
{
private:
	static SceneManager* s_instance;
	Scene* m_currentScene;

public:
	SceneManager();
	~SceneManager();
	static SceneManager* GetInstance();
	void Init(const string path);
	void Update(float deltaTime);
	void Render(sf::RenderWindow &window);
	void SwitchScene(Scene* scene);

};

SceneManager* SceneManager::s_instance = nullptr;

