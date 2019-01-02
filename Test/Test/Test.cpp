// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime> 
#include <iostream>
#include "SFML/Graphics.hpp"
#include"GameManager.h"

#define FPS_LIMIT 60
#define SPEED 350

using namespace sf;
using namespace std;
GameManager* GameManager::s_Instance = nullptr;

int main()
{
	VideoMode vd(WINDOWS_W, WINDOWS_H);
	//View view(Vector2f(WINDOWS_W/2,WINDOWS_H/2),Vector2f(WINDOWS_W,WINDOWS_H));
	View view(FloatRect(0,0,WINDOWS_W, WINDOWS_H));
	//view.setSize(WINDOWS_W, WINDOWS_H);
	RenderWindow window(vd, "Test",Style::Default);
	window.setFramerateLimit(FPS_LIMIT);
	Texture br;
	br.loadFromFile("resource/br.jpg");
	Sprite sprite;
	sprite.setTexture(br);
	
	/*============= Init =============*/
	//view.zoom(0.5);
	GameManager::getInstance()->Init();
	Clock clock;
	Time elapsed;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::LostFocus:
				//pause game - không chọn window hiện tại
				break;
			case Event::GainedFocus:
				//resume game - chọn lại window hiện tại
				break;
			case Event::TextEntered:
				//e.text.unicode - lấy kí tự nhận vào ghi ấn phím
				break;
			}
		}
		elapsed = clock.getElapsedTime();
		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		float dt = clock.getElapsedTime().asMicroseconds() * 1.0f / 1000000;
		clock.restart();
		float f = 0;
		/*============= Update =============*/
		//Mouse::getPosition(window).x -- lấy vị trí ở trong windows
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			GameManager::getInstance()->Update(dt,view);
			 f = GameManager::getInstance()->dis();
			 
			 
		}
		view.move(Vector2f(f, 0));
		cout << view.getCenter().x << " " << view.getCenter().y << endl;
		/*============= Draw =============*/
		
		//view.move(Vector2f(GameManager::getInstance()->dis(), 0));
		window.clear();
		window.setView(view);
		window.draw(sprite);
		GameManager::getInstance()->Render(window);
		window.display();
	}
	return 0;
}


