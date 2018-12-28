#pragma once
#include "SFML/Graphics.hpp"
#include <string>


using namespace sf;
using namespace std;


struct Position
{
	int m_x;
	int m_y;
};


class Object
{
protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	Position m_position;
	int m_velocity;
	int m_type;
	bool m_isAlive;

public:
	Object();
	~Object();
	void Update(float deltaTime);
	void Render(sf::RenderWindow &window);
};

