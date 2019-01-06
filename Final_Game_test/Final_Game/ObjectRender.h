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
	bool CheckCollision(sf::Sprite);
	sf::Sprite GetSprite();
	void setPos(float x, float y);
	Vector2f getPos();
	virtual void SetType(int type);
	virtual void SetAction();
	virtual void Init(const string path);
	void Update(float deltaTime);
	void Render(sf::RenderWindow &window);
};

