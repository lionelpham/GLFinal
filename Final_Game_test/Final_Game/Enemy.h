#pragma once

#include "Object.h"

class Enemy : public Object
{
private:
	int m_dir;

public:
	Enemy();
	~Enemy();
	void SetType(int type);
	void SetAction();
	void EnemyRotate();
	void Update(float dt);

};

