#include "CameraView.h"



void CameraView::InitView()
{
	view.reset(FloatRect(0, 0, WINDOWS_W, WINDOWS_H));
}

void CameraView::UpdateView(float deltaTime,int speed)
{
	view.move(Vector2f(speed*deltaTime,0));
}

void CameraView::SetView(RenderWindow &window)
{
	window.setView(view);
}

Vector2f CameraView::getCenterPos()
{
	return view.getCenter();
}

void CameraView::setPosition(Vector2f f)
{
	return view.setCenter(f);
}

CameraView::CameraView()
{
}


CameraView::~CameraView()
{
}
