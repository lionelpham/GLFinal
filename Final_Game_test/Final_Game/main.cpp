#include <math.h>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "SceneManager.h"
#include "Enemy.h"

using namespace sf;

#define WINDOWS_W	900
#define WINDOWS_H	600
#define FPS_LIMIT	60

#define PLAYER_SPEED	350
#define TEXTURE_PLAYER	"resources/player.png"
#define TEXTURE_ENEMY	"resources/enemy.png"

SceneManager* SceneManager::s_instance = nullptr;

int main()
{
	srand((unsigned int)time(NULL));
	RenderWindow window(VideoMode(WINDOWS_W, WINDOWS_H), "Alpha Jump Game!", Style::Default);
	window.setFramerateLimit(FPS_LIMIT);

	// ============================ Init ============================

	SceneManager::GetInstance()->Init(TEXTURE_ENEMY);
	Clock clock;
	Time elapsed;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		elapsed = clock.getElapsedTime();
		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		float dt = clock.getElapsedTime().asMicroseconds() * 1.0f / 1000000;
		// Start the countdown over.  Think of laps on a stop watch.
		clock.restart();

		// ================================ Update ================================ 

		SceneManager::GetInstance()->Update(dt);

		// ================================ Draw ================================ 

		window.clear();

		SceneManager::GetInstance()->Render(window);

		window.display();
	}

	return 0;
}