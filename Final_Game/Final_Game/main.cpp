#include <math.h>
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;

#define WINDOWS_W	900
#define WINDOWS_H	600
#define FPS_LIMIT	300

#define PLAYER_SPEED	350
#define TEXTURE_PLAYER	"resources/player.png"
#define TEXTURE_ENEMY	"resources/a1.png"


int main()
{
	srand((unsigned int)time(NULL));
	RenderWindow window(VideoMode(WINDOWS_W, WINDOWS_H), "Alpha Jump Game!", Style::Default);
	window.setFramerateLimit(FPS_LIMIT);

	// ============================ Init ============================

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
		//std::cout << "dt: " << dt << std::endl;
		// Start the countdown over.  Think of laps on a stop watch.
		clock.restart();

		// ================================ Update ================================ 

		// ================================ Draw ================================ 
		window.clear();

		window.display();
	}

	return 0;
}