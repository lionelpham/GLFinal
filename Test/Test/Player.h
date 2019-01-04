#pragma once
#include "GameObjectRender.h"

class Player : public GameObjectRender
{
private:
	float veloc;
	float mass;
public:
	void Update(float dt) override;
	Player();
	~Player();
};

