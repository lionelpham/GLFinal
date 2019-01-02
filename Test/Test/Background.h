#pragma once
#include "GameObjectRender.h"
class Background :
	public GameObjectRender
{
public:
	void Update(float dt, View &v) override;
	Background();
	~Background();
};

