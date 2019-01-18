#pragma once
#include "Background.h"
#include "Scene.h"
#include "Player.h"
#include "Logo.h"
#include "MusicEff.h"
#define SIZE_FONT 45
#define LOGO	"resources/glLogo.png"
#define BR_MENU "resources/bg.png"
#define TEXTURE_PLAYER	"resources/player.png"
#define FONT "resources/Cucho.otf"
#define FONT_T "resources/Alina.otf"

#define MAX_ITEMS 6
class MenuScene : public Scene
{
private:
	Background m_Background;
	//Background m_Logo;
	Logo m_Logo;
	Player m_Player;
	Font m_Font;
	Font m_Font_T;
	Text m_text[MAX_ITEMS];
	//choices = 0 -> Exit
	//choices = 1-> Option
	//choices = 2->Play
	int choices;
public:
	MenuScene();
	~MenuScene();
	void OnInit();
	void OnUpdate(float deltaTime,RenderWindow& window);
	void OnRender(sf::RenderWindow &window);
	int getScore();
	void setScore(int score);
	RenderWindow& getWindow(RenderWindow& window);
	int getState();
	int OnExit();
};

