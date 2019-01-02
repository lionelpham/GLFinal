#pragma once
#include "GameObjectRender.h"

class Player : public GameObjectRender
{
public:
	void Update(float dt);
	Player();
	~Player();
};

