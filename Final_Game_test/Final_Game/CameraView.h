#pragma once
#include "SFML/Graphics.hpp"
#define WINDOWS_W	900
#define WINDOWS_H	600
using namespace sf;
class CameraView
{
private:
	sf::View view;
public:
	void InitView();
	void UpdateView(float deltaTime, int speed);
	void SetView(RenderWindow &window);
	Vector2f getCenterPos();
	CameraView();
	~CameraView();
};

