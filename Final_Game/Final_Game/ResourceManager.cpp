#include "ResourceManager.h"



ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}


ResourceManager* ResourceManager::GetInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new ResourceManager();
	}
	return s_instance;
}


void ResourceManager::Init(const string path)
{
}


void ResourceManager::Load(string dataFile)
{
}


Image* ResourceManager::GetImageById(char id)
{
	Image* image;
	return image;
}


Font* ResourceManager::GetFontById(char id)
{
	Font* font;
	return font;
}

