#include "Rect.h"

Rect::Rect()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

Rect::Rect(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->width = w;
	this->height = h;
}

Rect::~Rect()
{
}
