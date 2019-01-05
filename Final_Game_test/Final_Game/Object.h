#pragma once

#include "SFML/Graphics.hpp"
#include <string>

#include "Collision.h"

#define WINDOWS_W	900
#define WINDOWS_H	600


using namespace sf;
using namespace std;


class Object
{
protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	int m_velocity;
	int m_type;
	bool m_isAlive;

public:
	Object();
	~Object();
	sf::Sprite GetSprite();
	virtual void SetType(int type);
	virtual void SetAction();
	virtual void Update(float deltaTime);
	void Init(const string path);
	void Render(sf::RenderWindow &window);
	bool CheckCollision(sf::Sprite );
};

