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
	}
	this->setPos(WINDOWS_W / 3 * 2 * m_type, WINDOWS_H / 2 - m_sprite.getTexture()->getSize().y/2);
}