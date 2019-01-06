#include "Animation.h"



Animation::Animation()
{
}


Animation::~Animation()
{
}


void Animation::Init(const string path)
{
	ObjectRender::Init(path);
	this->m_Frame = 0;
	int column = 0;
	int line = 0;
	//for (int i = 0; i < 16; i++) //Boom Effect
	//{
	//	line = i / 3;
	//	if (i % 3 == 0)
	//	{
	//		column = 0;
	//	}
	//	column++;
	//	this->m_animationFrames.push_back(IntRect(column*128, line* 128, 128, 128));
	//}

	//Electric Effect
	for (int i = 0; i < 9; i++)
	{
		this->m_animationFrames.push_back(IntRect(i * 150, 0, 150, 300));
	}
	this->m_sprite.setTextureRect(this->m_animationFrames[0]);
}


void Animation::setPos(float x, float y)
{
	m_sprite.setPosition(x, y);
}


void Animation::Update(float dt)
{
	this->m_Frame += dt*20;
	int n = this->m_animationFrames.size();
	if (this->m_Frame > n)
	{
		this->m_Frame -= n;
	}
	this->m_sprite.setTextureRect(this->m_animationFrames[int(this->m_Frame)]);
	this->m_sprite.setPosition(WINDOWS_W + 100, WINDOWS_H /4);
}