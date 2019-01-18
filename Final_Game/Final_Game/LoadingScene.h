#pragma once

#include "Scene.h"


class LoadingScene : public Scene 
{
public:
	LoadingScene();
	~LoadingScene();
	void OnInit();
	void OnUpdate(float deltaTime);
	void OnRender(sf::RenderWindow &window);
	int OnExit();
};

