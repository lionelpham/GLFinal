#pragma once

#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Scene
{
public:
	Scene();
	~Scene();
	virtual void OnInit() = 0;
	virtual void OnUpdate(float deltaTime) = 0;
	virtual void OnRender(sf::RenderWindow &window) = 0;
	virtual void OnExit() = 0;
};

