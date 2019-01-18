#include "Gem.h"



Gem::Gem()
{
}


Gem::~Gem()
{
}

void Gem::Init(const string path)
{
	switch (m_type)
	{
	case 1:
	{
		ObjectRender::Init(TEXTURE_GEM1);
		break;
	}
	case 2:
	{
		ObjectRender::Init(TEXTURE_GEM2);
		break;
	}
	case 3:
	{
		ObjectRender::Init(TEXTURE_GEM3);
		break;
	}
	case 4:
	{
		ObjectRender::Init(TEXTURE_GEM4);
		break;
	}
	case 5:
	{
		ObjectRender::Init(TEXTURE_GEM5);
		break;
	}
	case 6:
	{
		ObjectRender::Init(TEXTURE_GEM6);
		break;
	}
	case 7:
	{
		ObjectRender::Init(TEXTURE_GEM7);
		break;
	}
	case 8:
	{
		ObjectRender::Init(TEXTURE_GEM8);
		break;
	}
	case 9:
	{
		ObjectRender::Init(TEXTURE_GEM9);
		break;
	}
	case 10:
	{
		ObjectRender::Init(TEXTURE_GEM10);
		break;
	}
	}
	this->setPos(WINDOWS_W / 3 * 2 * m_type, WINDOWS_H / 2 - m_sprite.getTexture()->getSize().y / 2);
}