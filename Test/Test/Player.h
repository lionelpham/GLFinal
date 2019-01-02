#pragma once
#include "GameObjectRender.h"

class Player : public GameObjectRender
{
private:
	float s;
public:
	float getDis()
	{
		return s;
	}
	void Update(float dt, View &v) override;
	Player();
	~Player();
};

