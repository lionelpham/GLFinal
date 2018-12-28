#pragma once
#include "GameObjectRender.h"
#define Distance 400
class Player : public GameObjectRender
{
public:
	void Update(float dt) override;
	Player();
	~Player();
};

