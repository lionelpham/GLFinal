#pragma once
#include "ObjectRender.h"
class Logo : public ObjectRender
{
public:
	void setSizeLogo();
	void setPositionLogo(Vector2f f);
	Logo();
	~Logo();
};

