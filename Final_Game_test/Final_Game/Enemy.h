#pragma once

#include "ObjectRender.h"

#define TEXTURE_STONE1	"resources/stone_vertical1.png"
#define TEXTURE_STONE2	"resources/stone_vertical2.png"
#define TEXTURE_NINJA	"resources/ninja_weapon.png"
#define TEXTURE_MOON	"resources/half_moon.png"
#define TEXTURE_PIG		"resources/pig.png"

#define ROCK_SPEED 200
#define NINJA_SPEED 400

class Enemy : public ObjectRender
{
private:
	int m_dir;

public:
	Enemy();
	~Enemy();
	void SetType(int type);
	void SetAction();
	void EnemyRotate(float angle);
	void Init(const string path);
	void Update(float dt) override;
};

