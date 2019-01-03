#pragma once

#include "Scene.h"


class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();
	void OnInit();
	void OnUpdate(float deltaTime);
	void OnRender(sf::RenderWindow &window);
	void OnExit();
};

