#pragma once

#include "Object.h"


class ResourceManager
{
private:
	static ResourceManager* s_instance;
	string m_dataFolderPatch;
	map<char, Image*> m_image;
	map<char, Font*> m_fonts;

public:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* GetInstance();
	void Init(const string path);
	void Load(string dataFile);
	Image* GetImageById(char id);
	Font* GetFontById(char id);

};
ResourceManager* ResourceManager::s_instance = nullptr;
