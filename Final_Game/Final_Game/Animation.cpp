#include "Animation.h"


Animation::Animation()
{
	this->m_isAlive = 1;
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
			this->m_animationFrames.push_back(IntRect(column * 128, line * 128, 128, 128));
		}
		break;

	}
	case 3:
	{
		for (int i=0;i<6;i++)
		{
			this->m_animationFrames.push_back(IntRect(0, i * 30, 72, 30));
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
	}
	case 2:
	{
		ObjectRender::Init(TEXTURE_ANIMATION_DESTROY);		//If boom animation
		break;
	}
	case 3:
	{
		ObjectRender::Init(TEXTURE_ANIMATION_RUN);
		break;
	}
	default:
		break;
	}
	SetAnimation();
}


void Animation::Update(float dt)
{
	switch (m_type)
	{
	case 1:
	case 2:
	{
		if (m_isAlive)
		{
			this->m_Frame += dt * 10;
			int n = this->m_animationFrames.size();
			if (this->m_Frame >= n)
			{
				this->m_isAlive = 0;
				return;
			}
			this->m_sprite.setTextureRect(this->m_animationFrames[int(this->m_Frame)]);
		}
		break;
	}
	case 3:
	{
		this->m_Frame += dt*15;
		int n = this->m_animationFrames.size();
		if (this->m_Frame > n)
		{
			this->m_Frame -= n;

		}
		this->m_sprite.setTextureRect(this->m_animationFrames[int(this->m_Frame)]);
		break;
	}
	}
}