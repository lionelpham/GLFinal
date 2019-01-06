#pragma once

#include "ObjectRender.h"

class Player : public ObjectRender
{
public:
	void setSize();
	void Init(const string path);
	void Update(float dt) override;
	Player();
	~Player();
};

