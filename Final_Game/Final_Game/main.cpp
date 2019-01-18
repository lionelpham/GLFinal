#include <math.h>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "SceneManager.h"
#include "Enemy.h"
#include "MusicEff.h"
using namespace sf;

#define WINDOWS_W	900
#define WINDOWS_H	600
#define POSITION_X 50
#define POSITION_Y 50
#define FPS_LIMIT	60


#define TEXTURE_PLAYER	"resources/player.png"
#define TEXTURE_ENEMY	"resources/enemy.png"


SceneManager* SceneManager::s_instance = nullptr;
MusicEff * MusicEff::s_instace = nullptr;
int main()
{
	srand((unsigned int)time(NULL));
	RenderWindow window(VideoMode(WINDOWS_W, WINDOWS_H), "Alpha Jump Game!", Style::Default);
	window.setPosition(Vector2i(POSITION_X, POSITION_Y));
	window.setFramerateLimit(FPS_LIMIT);
	//Music br_sound;
	//br_sound.openFromFile(MUSIC_BR);
	//br_sound.setLoop(true);
	//br_sound.play();
	// ============================ Init ============================

	SceneManager::GetInstance()->Init(window);
	MusicEff::getInstance()->Init();
	Clock clock;
	Time elapsed;
	MusicEff::getInstance()->startPreBrMusic();

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
		//Vector2i position = Mouse::getPosition(window);
		
		SceneManager::GetInstance()->Update(dt,window);

		// ================================ Draw ================================ 

		window.clear();

		SceneManager::GetInstance()->Render(window);

		window.display();
	}
	MusicEff::getInstance()->stopPreBrMusic();
	return 0;
}