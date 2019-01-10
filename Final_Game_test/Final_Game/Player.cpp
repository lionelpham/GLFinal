#include "Player.h"
#include<iostream>
#define SPEED 400


Player::Player()
{

	//Set player still alive
	m_isAlive = true;
}


Player::~Player()
{
}


//Set size for player
void Player::setSize()
{
	m_sprite.setScale(0.7, 0.7);
}


//Set player dead
void Player::Die()
{
	m_isAlive = false;
}


//Check player still alive or die
bool Player::checkAlive()
{
	return m_isAlive;
}


void Player::Init(const string path)
{
	
	ObjectRender::Init(path);	
	//Call Object Render Init function
	this->setPos(0, WINDOWS_H / 2 - m_texture.getSize().y/2);		//Set position for player
	this->setSize();					//Set size for player

}


void Player::Update(float dt)
{

	//Update player when click mouse
	m_sprite.setPosition(m_sprite.getPosition().x + 2 * SPEED*dt, m_sprite.getPosition().y);

}



