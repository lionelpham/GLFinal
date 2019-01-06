#pragma once
#include "ObjectRender.h"
class Background : public ObjectRender
{
public:
	Background();
	~Background();
	void fixSize();
	void Init(const string path) override;
	void Update(float deltatime) override;
	
};

