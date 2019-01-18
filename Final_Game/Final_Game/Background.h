#pragma once
#include "ObjectRender.h"
class Background : public ObjectRender
{
public:
	Background();
	~Background();
	void fixSize();
	void Init(const string path);
	void Update(float deltatime) override;
	void setPosition(Vector2f f);
	void fixScale();
};

