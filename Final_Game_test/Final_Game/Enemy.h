#pragma once
#include "Object.h"
class Enemy : public Object
{
private:
	int m_dir;
public:
	Enemy();
	~Enemy();
	void setType(int type);
	void EnemyUp(float &);
	void EnemyDown(float &);
	void EnemyRotate();
	void Update(float dt);
};

