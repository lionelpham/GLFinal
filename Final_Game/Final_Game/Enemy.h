#pragma once

#include "ObjectRender.h"


#define TEXTURE_STONE1		"resources/stone_vertical1.png"
#define TEXTURE_STONE2		"resources/stone_vertical2.png"
#define TEXTURE_STATION1	"resources/space_station_1.png"
#define TEXTURE_STATION2	"resources/space_station_2.png"
#define TEXTURE_NINJA		"resources/ninja_weapon.png"
#define TEXTURE_UFOBLUE		"resources/ufoBlue.png"
#define TEXTURE_UFOGREEN	"resources/ufoGreen.png"
#define TEXTURE_SHURIKEN	"resources/shuriken.png"
#define TEXTURE_PIG			"resources/pig.png"
#define TEXTURE_ALIEN		"resources/alien.png"
#define TEXTURE_LIGHTING	"resources/lighting.png"
#define TEXTURE_BLADE		"resources/blade.png"
#define TEXTURE_BLADE1		"resources/blade1.png"
#define TEXTURE_BLADE2		"resources/blade2.png"
#define	TEXTURE_CURVE		"resources/curve.png"
#define TEXTURE_4KNIFE		"resources/4knife.png"


#define ROCK_SPEED 200
#define LIGHTING_SPEED 400
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

