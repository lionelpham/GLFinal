#pragma once

#include "ObjectRender.h"

class Enemy : public ObjectRender
{
private:
	int m_dir;

public:
	Enemy();
	~Enemy();
	void SetType(int type);
	void SetAction();
	void EnemyRotate();
	void Init(const string path);
	void Update(float dt) override;
};

