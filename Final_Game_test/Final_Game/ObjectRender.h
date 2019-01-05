#pragma once

#include "Object.h"
#include "Collision.h"


class ObjectRender : public Object
{
protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	int m_velocity;
	int m_type;
	bool m_isAlive;
public:
	ObjectRender();
	~ObjectRender();
	sf::Sprite GetSprite();
	virtual void SetType(int type);
	virtual void SetAction();
	bool CheckCollision(sf::Sprite);
	void Init(const string path);
	void Render(sf::RenderWindow &window);
	void Update(float deltaTime);
};

