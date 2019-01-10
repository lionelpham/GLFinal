#pragma once

#include "ObjectRender.h"

#define TEXTURE_GEM1	"resources/gem1.png"
#define TEXTURE_GEM2	"resources/gem2.png"
#define TEXTURE_GEM3	"resources/gem3.png"

class Gem : public ObjectRender
{
public:
	Gem();
	~Gem();
	void Init(const string path);
};

