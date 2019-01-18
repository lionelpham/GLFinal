#pragma once

#include "ObjectRender.h"

#define TEXTURE_GEM1	"resources/gem1.png"
#define TEXTURE_GEM2	"resources/gem2.png"
#define TEXTURE_GEM3	"resources/gem3.png"
#define TEXTURE_GEM4	"resources/gem4.png"
#define TEXTURE_GEM5	"resources/gem5.png"
#define TEXTURE_GEM6	"resources/gem6.png"
#define TEXTURE_GEM7	"resources/gem7.png"
#define TEXTURE_GEM8	"resources/gem8.png"
#define TEXTURE_GEM9	"resources/gem9.png"
#define TEXTURE_GEM10	"resources/gem10.png"


class Gem : public ObjectRender
{
public:
	Gem();
	~Gem();
	void Init(const string path);
};

