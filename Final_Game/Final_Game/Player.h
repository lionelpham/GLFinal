#pragma once

#include "ObjectRender.h"

class Player : public ObjectRender
{
public:
	void setSize();
	void Die();
	void setPosi();
	bool CheckAlive();
	void Init(const string path);
	void Update(float dt,int speed) ;
	Player();
	~Player();
};

