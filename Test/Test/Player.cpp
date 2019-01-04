#include "pch.h"
#include "Player.h"


void Player::Update(float dt)
{
	sprite.setPosition(sprite.getPosition().x + 2*veloc*dt,sprite.getPosition().y);
}

Player::Player()
{
	veloc = SPEED;
}


Player::~Player()
{
}
