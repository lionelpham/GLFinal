#include "pch.h"
#include "Enemy.h"


void Enemy::Update(float dt)
{
	sprite.setPosition(sprite.getPosition().x + SPEED * dt, sprite.getPosition().y);
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
