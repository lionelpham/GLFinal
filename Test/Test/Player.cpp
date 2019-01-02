#include "pch.h"
#include "Player.h"


void Player::Update(float dt, View &v)
{
	s = (SPEED-50) * dt;
	sprite.setPosition(sprite.getPosition().x + SPEED*dt,sprite.getPosition().y);
	cout << sprite.getPosition().x << " " << sprite.getPosition().y << endl;
}

Player::Player()
{
	s = 0;
}


Player::~Player()
{
}
