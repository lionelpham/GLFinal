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
	/*Enemy enemy1;
	Enemy enemy2;
	Enemy enemy3;*/
	SceneManager::GetInstance()->Init(TEXTURE_ENEMY);
	Clock clock;
	Time elapsed;
	/*enemy1.setType(1);
	enemy1.Init(TEXTURE_ENEMY);
	enemy2.setType(2);
	enemy2.Init(TEXTURE_ENEMY);
	enemy3.setType(3);
	enemy3.Init(TEXTURE_ENEMY);*/

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
		/*enemy1.Update(dt);
		enemy2.Update(dt);
		enemy3.Update(dt);*/
		SceneManager::GetInstance()->Update(dt);
		// ================================ Draw ================================ 
		window.clear();
		SceneManager::GetInstance()->Render(window);
		/*enemy1.Render(window);
		enemy2.Render(window);
		enemy3.Render(window);*/
		window.display();
	}

	return 0;
}