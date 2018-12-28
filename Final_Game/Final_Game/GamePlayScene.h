#pragma once

#include "Scene.h"


class GamePlayScene : public Scene
{
public:
	GamePlayScene();
	~GamePlayScene();
	void OnInit();
	void OnUpdate(float deltaTime);
	void OnRender(sf::RenderWindow &window);
	void OnExit();
};

