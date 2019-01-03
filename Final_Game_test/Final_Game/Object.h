#pragma once
#include "SFML/Graphics.hpp"
#include <string>

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
	void setType(int type);
	void Init(const string path);
	void Update(float deltaTime);
	void Render(sf::RenderWindow &window);

};

