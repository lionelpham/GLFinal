#pragma once

#include "Scene.h"


class GameOverScene : public Scene
{
public:
	GameOverScene();
	~GameOverScene();
	void OnInit();
	void OnUpdate(float deltaTime);
	void OnRender(sf::RenderWindow &window);
	void OnExit();
};

