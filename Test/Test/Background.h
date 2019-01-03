#pragma once
#include "GameObjectRender.h"
class Background :
	public GameObjectRender
{
public:
	void Init(const char * textureName, int x, int y) override;
	void setSize();
	void Update(float dt) override;
	void Move(Vector2f f);
	Background();
	~Background();
};

