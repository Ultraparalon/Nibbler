#include "Button.h"

Button::Button() : Drawable() {}

Button::Button(const int y, const int x, const int height, const int width,
	const eTexture txr) : Drawable(y, x, height, width, txr, "button") {}

Button::~Button() {}

bool Button::clicked(const int y, const int x)
{
	int startY = this->getPosY() * this->getHeight();
	int startX = this->getPosX() * this->getWidth();
	
	if (y > startY && y < startY + this->getHeight() &&
		x > startX && x < startX + this->getWidth())
	{
		return true;
	}
	return false;
}
