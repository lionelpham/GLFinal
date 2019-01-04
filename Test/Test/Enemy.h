#pragma once
#include "GameObjectRender.h"
class Enemy :
	public GameObjectRender
{
public:
	void Update(float dt) override;
	Vector2f getPosition();

	Enemy();
	~Enemy();
};

