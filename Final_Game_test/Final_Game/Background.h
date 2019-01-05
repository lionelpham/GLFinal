#pragma once
#include "ObjectRender.h"
class Background : public ObjectRender
{
public:
	void fixSize();
	void Update(float deltatime) override;
	Background();
	~Background();
};

