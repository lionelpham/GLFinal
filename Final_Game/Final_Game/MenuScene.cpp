#include "MenuScene.h"
#include <iostream>


MenuScene::MenuScene()
{
	choices = -1;
}


MenuScene::~MenuScene()
{
}


void MenuScene::OnInit()
{
	
	m_Background.Init(BR_MENU);
	m_Logo.Init(LOGO);
	m_Logo.setPositionLogo(Vector2f(-15, 10));
	m_Logo.setSizeLogo();
	m_Player.Init(TEXTURE_PLAYER);

	if (!m_Font.loadFromFile(FONT)) {
		std::cout << "Fail to load font" << std::endl;
	}
	if (!m_Font_T.loadFromFile(FONT_T)) {
		std::cout << "Fail to load font" << std::endl;
	}


	

	//Play button
	m_text[0].setFont(m_Font);
	m_text[0].setColor(Color::Yellow);
	m_text[0].setString("Play");
	m_text[0].setStyle(Text::Style::Bold);
	m_text[0].setPosition(Vector2f(WINDOWS_W / 2 - 40, 2 * WINDOWS_H / 5));
	m_text[0].setCharacterSize(SIZE_FONT);
	//m_text[0].setOrigin(10, 10);
	//Option Button
	m_text[1].setFont(m_Font);
	m_text[1].setColor(Color::Yellow);
	m_text[1].setString("Option");
	m_text[1].setStyle(Text::Style::Bold);
	m_text[1].setPosition(Vector2f(WINDOWS_W / 2 - 40, 3 * WINDOWS_H / 5));
	m_text[1].setCharacterSize(SIZE_FONT);
	//Exit Button
	m_text[2].setFont(m_Font);
	m_text[2].setColor(Color::Yellow);
	m_text[2].setString("Exit");
	m_text[2].setStyle(Text::Style::Bold);
	m_text[2].setPosition(Vector2f(WINDOWS_W / 2 - 40, 4 * WINDOWS_H / 5));
	m_text[2].setCharacterSize(SIZE_FONT);
	//Alpha
	m_text[3].setFont(m_Font_T);
	m_text[3].setColor(Color::Yellow);
	m_text[3].setString("Alpha");
	m_text[3].setPosition(Vector2f(WINDOWS_W / 4, 30));
	m_text[3].setCharacterSize(140);
	m_text[3].rotate(-10);
	m_text[3].setOutlineColor(Color::White);
	m_text[3].setOutlineThickness(1.2);
	//Jump
	m_text[4].setFont(m_Font_T);
	m_text[4].setColor(Color::Yellow);
	m_text[4].setString("Jump");
	m_text[4].setPosition(Vector2f(WINDOWS_W / 2 + 80, 30));
	m_text[4].setCharacterSize(130);
	m_text[4].setOutlineColor(Color::White);
	m_text[4].setOutlineThickness(1);
	//LEAP PROGRAM
	m_text[5].setFont(m_Font);
	m_text[5].setColor(Color::Black);
	m_text[5].setString("LEAP PROGRAM");
	m_text[5].setStyle(Text::Style::Bold);
	m_text[5].setPosition(Vector2f(25, 145));
	m_text[5].setCharacterSize(20);
	m_text[5].setOutlineColor(Color::White);
	m_text[5].setOutlineThickness(1);

	//cout << "Play " << m_text[0].getPosition().x << m_text[0].getPosition().y << " " << m_text[0].getOrigin().x << endl;
	//cout << "Option " << m_text[1].getPosition().x << m_text[1].getPosition().y << endl;
	//cout << "Exit " << m_text[2].getPosition().x << m_text[2].getPosition().y << endl;
	//cout << "Play" << m_text[0].getLocalBounds() << m_text[0].getPosition().y << endl;
	//cout << "Play" << m_text[0].getSize().x << m_text[0].getPosition().y << endl;
}


void MenuScene::OnUpdate(float deltaTime, RenderWindow& window)
{

	m_Background.Update(deltaTime);
	//if(Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition())
	//chung 1 vị trí x
	Vector2i a = Mouse::getPosition(window);
	//cout << a.x << " " << a.y << endl;


	//Play button
	if (m_text[0].getGlobalBounds().contains(Vector2f(a)))
	{
		m_text[0].setFillColor(Color::White);
		//Xử lý click
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			//if(MusicEff::getInstance()->statusStartMusic()==true)
			MusicEff::getInstance()->pauseBrMusic();
			//if(MusicEff::getInstance()->statusPauseMusic()==true)
			MusicEff::getInstance()->startPlay();
			choices = 2;
			//if (MusicEff::getInstance()->statusStartMusic() == false)
			
			return;
		}
	}
	else
	{
		m_text[0].setFillColor(Color::Yellow);
	}
	//Option Button
	if (m_text[1].getGlobalBounds().contains(Vector2f(a)))
	{
		m_text[1].setFillColor(Color::White);
		//Xử lý click
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			choices = 1;
			return;
		}
	}
	else
	{
		m_text[1].setFillColor(Color::Yellow);
	}
	//Exit Button
	if (m_text[2].getGlobalBounds().contains(Vector2f(a)))
	{
		m_text[2].setFillColor(Color::White);
		//Xử lý click
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			MusicEff::getInstance()->pauseBrMusic();
			MusicEff::getInstance()->startExit();
			choices = 0;
			return;
		}
	}
	else
	{
		m_text[2].setFillColor(Color::Yellow);
	}
}




void MenuScene::OnRender(sf::RenderWindow &window)
{
	m_Background.Render(window);
	m_Logo.Render(window);
	m_Player.Render(window);
	for (int i = 0; i < MAX_ITEMS; i++)
		window.draw(m_text[i]);
}

int MenuScene::getScore()
{
	return 0;
}

void MenuScene::setScore(int score)
{
}



RenderWindow& MenuScene::getWindow(RenderWindow & window)
{
	return window;
}







int MenuScene::getState()
{
	return choices;
}


int MenuScene::OnExit()
{
	return choices;
}
