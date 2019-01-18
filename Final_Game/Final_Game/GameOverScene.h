#pragma once
#include "Background.h"
#include "Scene.h"
#include "MusicEff.h"
#define WINDOWS_W 900
#define WINDOWS_H 600
#define SIZE_F 100
#define FONT_T "resources/Cucho.otf"
#define BR_MENU "resources/bg.png"
#define MAX_ITEMS_OVERS 4
class GameOverScene : public Scene
{
private:
	Background m_Background;
	Text m_text[MAX_ITEMS_OVERS];
	Font m_font;
	int state;
	int m_score;
	//RenderWindow w;
public:
	GameOverScene();
	~GameOverScene();
	void OnInit();
	//void setCursor(RenderWindow &window);
	RenderWindow& getWindow(RenderWindow &window);
	int getScore();
	void setScore(int score);

	void OnUpdate(float deltaTime, RenderWindow& window);
	void OnRender(sf::RenderWindow &window);
	int OnExit();
};

