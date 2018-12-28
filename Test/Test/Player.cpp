#include "pch.h"
#include "Player.h"


void Player::Update(float dt)
{
	
		sprite.setPosition(sprite.getPosition().x + SPEED*dt,sprite.getPosition().y);
	
}

Player::Player()
{
}


Player::~Player()
{
}
