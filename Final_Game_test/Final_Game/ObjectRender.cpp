#include "ObjectRender.h"

//Constructors

ObjectRender::ObjectRender()
{
}

//Deconstructors

ObjectRender::~ObjectRender()
{
}

//Set type for Object Render 
//Input: int type

void ObjectRender::SetType(int type)
{
	m_type = type;
}

//Get sprite of Object Render
//Output: sf::sprite

sf::Sprite ObjectRender::GetSprite()
{
	return m_sprite;
}

//Set position for Object Render
//Input: float x, float y

void ObjectRender::setPos(float x, float y)
{
	m_sprite.setPosition(x, y);
}

//Get position for Object Render
//Output: Vector2f of position

Vector2f ObjectRender::getPos()
{
	return m_sprite.getPosition();
}

//Set action for object render

void ObjectRender::SetAction()
{
}

//Check collision between 2 Object Render
//Output: bool value (1: collision, 0: no collision)

bool ObjectRender::CheckCollision(sf::Sprite sprite)
{
	return (Collision::PixelPerfectTest(this->GetSprite(), sprite));
}

//Init Object Render
//Input: path of texture for Object Render

void ObjectRender::Init(const string path)
{
	Collision::CreateTextureAndBitmask(m_texture, path);
	m_sprite.setTexture(m_texture);
}

//Update Object Render
//Input: delta time

void ObjectRender::Update(float deltaTime)
{
}

//Render object
//Input: window render 

void ObjectRender::Render(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}

