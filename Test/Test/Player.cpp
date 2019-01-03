#include "pch.h"
#include "Player.h"


<<<<<<< HEAD
Player::Player()
{
=======
void Player::Update(float dt)
{
	sprite.setPosition(sprite.getPosition().x + 2*SPEED*dt,sprite.getPosition().y);
}

Player::Player()
{
	
>>>>>>> master
}


Player::~Player()
{
}
