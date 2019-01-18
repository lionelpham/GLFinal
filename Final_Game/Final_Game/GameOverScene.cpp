#include "GameOverScene.h"
#include <iostream>

GameOverScene::GameOverScene()
{
	
	state = -1;
}


GameOverScene::~GameOverScene()
{
}

void GameOverScene::OnInit()
{
	MusicEff::getInstance()->pauseBrMusic();
	MusicEff::getInstance()->startOverMusic();
	m_Background.Init(BR_MENU);
	if (!m_font.loadFromFile(FONT_T)) {
		std::cout << "Fail to load font" << std::endl;
	}
	//Game over
	m_text[0].setFont(m_font);
	m_text[0].setColor(Color::Color(186,2,2));
	m_text[0].setString("GAME OVER");
	m_text[0].setStyle(Text::Style::Bold);
	m_text[0].setPosition(Vector2f(WINDOWS_W / 4,  50));
	m_text[0].setCharacterSize(SIZE_F);
	m_text[0].setOutlineColor(Color::White);
	m_text[0].setOutlineThickness(0.9);
	//score
	char s_score[255]="";
	itoa(m_score, s_score,10);

	m_text[1].setFont(m_font);
	m_text[1].setColor(Color::Color(255, 255, 255));
	m_text[1].setString(s_score);
	m_text[1].setStyle(Text::Style::Bold);
	m_text[1].setPosition(Vector2f(WINDOWS_W / 2-10, WINDOWS_H/3-25));
	m_text[1].setCharacterSize(SIZE_F);
	//play again
	m_text[2].setFont(m_font);
	m_text[2].setColor(Color::Green);
	m_text[2].setString("Play Again");
	m_text[2].setStyle(Text::Style::Bold);
	m_text[2].setPosition(Vector2f(WINDOWS_W / 2 - 100, WINDOWS_H/2+50));
	m_text[2].setCharacterSize(50);
	/*m_text[2].setOutlineColor(Color::White);
	m_text[2].setOutlineThickness(1);*/
	//exit
	m_text[3].setFont(m_font);
	m_text[3].setColor(Color::Green);
	m_text[3].setString("Exit");
	m_text[3].setStyle(Text::Style::Bold);
	m_text[3].setPosition(Vector2f(WINDOWS_W / 2 -40,3* WINDOWS_H/4 ));
	m_text[3].setCharacterSize(50);
	/*m_text[3].setOutlineColor(Color::White);
	m_text[3].setOutlineThickness(1);*/
	//cout << m_text[2].getPosition().x << " " << m_text[2].getPosition().y << endl;
	//cout << m_text[3].getPosition().x <<" " <<m_text[3].getPosition().y << endl;
	
}

//void GameOverScene::setCursor(RenderWindow & window)
//{
//	m_position = Mouse::getPosition(window);
//}


RenderWindow& GameOverScene::getWindow(RenderWindow & window)
{

	return window;
}

int GameOverScene::getScore()
{
	return -1;
}

void GameOverScene::setScore(int score)
{
	m_score = score;
}






void GameOverScene::OnUpdate(float deltaTime, RenderWindow& window)
{
	m_Background.Update(deltaTime);
	Vector2i a = Mouse::getPosition(window);
	
	if (m_text[2].getGlobalBounds().contains(Vector2f(a)))
	{
		m_text[2].setFillColor(Color::White);
		//Xử lí click - play again
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			MusicEff::getInstance()->pauseBrMusic();
			MusicEff::getInstance()->startPlay();
			
			state = 2;
			sleep(microseconds(5000));
			return;
		}
	}
	else 
		m_text[2].setFillColor(Color::Green);

	if (m_text[3].getGlobalBounds().contains(Vector2f(a)))
	{
		m_text[3].setFillColor(Color::White);
		//Xử lí click
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			state = 0;
			MusicEff::getInstance()->pauseBrMusic();
			MusicEff::getInstance()->startExit();
			return;
		}
	}
	else
		m_text[3].setFillColor(Color::Green);
}


void GameOverScene::OnRender(sf::RenderWindow &window)
{
	m_Background.Render(window);
	for (int i = 0; i < MAX_ITEMS_OVERS; i++)
		window.draw(m_text[i]);
}


int GameOverScene::OnExit()
{
	return state;
}
