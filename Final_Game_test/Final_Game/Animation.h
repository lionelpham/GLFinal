#pragma once

#include <vector>

#include "ObjectRender.h"


class Animation : public ObjectRender
{
private:
	float m_Frame;
	vector<IntRect> m_animationFrames;

public:
	Animation();
	~Animation();
	void Init(const string path) override;
	void SetAnimation();
	void Update(float dt);
};

