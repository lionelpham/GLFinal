#include "Logo.h"



void Logo::setSizeLogo()
{
	m_texture.setSmooth(true);
	m_sprite.setScale(0.22,0.22);
}

void Logo::setPositionLogo(Vector2f f)
{
	m_sprite.setPosition(f);
}

Logo::Logo()
{
}


Logo::~Logo()
{
}
