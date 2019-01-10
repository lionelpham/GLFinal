#include "Animation.h"

#define TEXTURE_ANIMATION_DESTROY "resources/destroy.png"
#define TEXTURE_ANIMATION_ELECTRIC "resources/electric.png"


Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::SetAnimation()
{
	this->m_Frame = 0;
	switch (m_type)
	{
	case 1:
	{
		//Electric Effect
		this->m_sprite.setPosition(WINDOWS_W + 100, WINDOWS_H / 4);
		for (int i = 0; i < 9; i++)
		{
			this->m_animationFrames.push_back(IntRect(i * 150, 0, 150, 300));
		}
		this->m_sprite.setTextureRect(this->m_animationFrames[0]);
		break;
	}
	case 2:
	{
		//Boom Effect
		int column = 0;
		int line = 0;
		for (int i = 0; i < 16; i++) 
		{
			line = i / 3;
			if (i % 3 == 0)
			{
				column = 0;
			}
			column++;
			this->m_animationFrames.push_back(IntRect(column*128, line* 128, 128, 128));
		}
		break;

	}
	default:
		break;
	}
}

void Animation::Init(const string path)
{
	
	switch (m_type)
	{
	case 1:													//If electric animation
	{
		ObjectRender::Init(TEXTURE_ANIMATION_ELECTRIC);
		break;
	}
	case 2:
	{
		ObjectRender::Init(TEXTURE_ANIMATION_DESTROY);		//If boom animation
		break;
	}
	default:
		break;
	}
	SetAnimation();
}


void Animation::Update(float dt)
{
	this->m_Frame += dt*10;
	int n = this->m_animationFrames.size();
	if (this->m_Frame > n)
	{
		this->m_Frame -= n;
	}
	this->m_sprite.setTextureRect(this->m_animationFrames[int(this->m_Frame)]);
}