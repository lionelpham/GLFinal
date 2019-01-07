#pragma once

#include "ObjectRender.h"

class Player : public ObjectRender
{
public:
	void setPos(float x, float y);
	Vector2f getPos();
	void setSize();
	void Update(float dt, int speed);
	Player();
	~Player();
};

