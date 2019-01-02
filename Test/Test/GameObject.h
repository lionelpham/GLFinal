#pragma once
#include "SFML/Graphics.hpp"

#include <iostream>
using namespace std;
using namespace sf;

class GameObject
{
public:
	virtual void Init(const char* textureName = "", int x = 0, int y = 0) = 0;
	virtual void Update(float dt, View &v) = 0;
	virtual void Render(RenderWindow &window) = 0;

	GameObject();
	~GameObject();
};

