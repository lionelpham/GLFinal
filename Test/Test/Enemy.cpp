#include "pch.h"
#include "Enemy.h"


void Enemy::Update(float dt, View &v)
{
	sprite.setPosition(sprite.getPosition().x + 1500 * dt, sprite.getPosition().y);
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
