#pragma once

#include "GamePlayScene.h"
#include "MenuScene.h"
#include "GameOverScene.h"

class SceneManager
{
private:
	static SceneManager* s_instance;
	Scene* m_currentScene;
	int scene;
	int score;
public:
	SceneManager();
	~SceneManager();
	static SceneManager* GetInstance();
	void Init(RenderWindow &window);
	void Update(float deltaTime,RenderWindow& window);
	void Render(sf::RenderWindow &window);
	void SwitchScene(Scene* scene);

};


