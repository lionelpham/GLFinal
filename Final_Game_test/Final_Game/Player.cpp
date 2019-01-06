#include "Player.h"

#define SPEED 400


void Player::setSize()
{
	m_sprite.setScale(0.1, 0.1);
}


void Player::Init(const string path)
{

	ObjectRender::Init(path);			//Call Object Render Init function
	this->setPos(0, WINDOWS_H / 2);		//Set position for player
	this->setSize();					//Set size for player

}
void Player::Update(float dt)
{

	//Update player when click mouse
	m_sprite.setPosition(m_sprite.getPosition().x + 2 * SPEED*dt, m_sprite.getPosition().y);

}

Player::Player()
{

	//Set player still alive
	m_isAlive = true;

}


Player::~Player()
{
}
