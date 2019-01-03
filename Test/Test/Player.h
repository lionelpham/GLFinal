#pragma once
#include "GameObjectRender.h"

class Player : public GameObjectRender
{
private:

public:
	void Update(float dt) override;
	Player();
	~Player();
};

