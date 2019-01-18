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
	virtual void OnUpdate(float deltaTime,RenderWindow &window) = 0;
	virtual int getScore() = 0;
	virtual void setScore(int score) = 0;
	virtual RenderWindow& getWindow(RenderWindow &window) = 0;
	virtual void OnRender(sf::RenderWindow &window) = 0;
	virtual int OnExit() = 0;
};

