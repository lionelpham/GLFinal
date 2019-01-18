#pragma once

#include "SFML/Graphics.hpp"
#include <string>


#define WINDOWS_W	900
#define WINDOWS_H	600
#define POSITION_X 50
#define POSITION_Y 50


using namespace sf;
using namespace std;


class Object
{
protected:
public:
	Object();
	~Object();
	virtual void Update(float deltaTime) = 0;
	virtual void Init(const string path) = 0;
	virtual void Render(sf::RenderWindow &window) = 0;
};

