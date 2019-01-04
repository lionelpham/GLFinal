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
#define SPEED 500
#define SPEED_VIEW 200
#define SPEED_ENEMY 300
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
	//view.setViewport(FloatRect(0.f, -0.5f, 1.0f, 1.0f));
	
	/*============= Init =============*/
	//view.zoom(0.5);
	GameManager::getInstance()->Init();
	Clock clock;

	Time elapsed;
	//int counter = 0;
	
	while (window.isOpen())
	{
		Event event;
		//GameManager::getInstance()->brMove();
		//sprite.move(-0.8, 0);
		//int counterClick = 0;
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
		
		GameManager::getInstance()->brUpdate(dt);
		/*============= Update =============*/
		//Mouse::getPosition(window).x -- lấy vị trí ở trong windows
		if (event.type == Event::MouseButtonPressed)
		{
			if(event.mouseButton.button == Mouse::Left)
			GameManager::getInstance()->Update(dt);
			//counter++;
		}
		//cout << counter << endl;
		//if (event.type == Event::MouseButtonReleased) {
			
			
			cout << GameManager::getInstance()->dis().x << "  " << view.getCenter().x<<endl;
			//update lai view
			float distance = (view.getCenter().x - WINDOWS_W / 2) - GameManager::getInstance()->dis().x;
			cout << "dis " << distance << endl;
			if (-distance > 100)
			{
				view.move(Vector2f((4*SPEED_VIEW*dt), 0));
			}
			else if (-distance > 50)
			{
				view.move(Vector2f((2 * SPEED_VIEW*dt), 0));
			}
			else if (-distance>0) { 
				view.move(Vector2f((SPEED_VIEW*dt), 0));
				//view.setCenter(Vector2f(view.getCenter().x + SPEED_VIEW * dt, view.getCenter().y));
			}
		//}

		//cout << view.getCenter().x << " " << view.getCenter().y << endl;
		/*============= Draw =============*/
		
		//view.move(Vector2f(GameManager::getInstance()->dis(), 0));
		window.clear();
		window.setView(view);
		//window.draw(sprite);
		GameManager::getInstance()->Render(window);
		window.display();
	}
	return 0;
}


