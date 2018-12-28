#pragma once
#include "GameObjectRender.h"
class Enemy :
	public GameObjectRender
{
public:
	void Update(float dt) override;
	Enemy();
	~Enemy();
};

