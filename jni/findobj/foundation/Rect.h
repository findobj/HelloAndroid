#ifndef __RECT_H__
#define __RECT_H__

#include "Object.h"

class Rect : public Object
{
public:
	Rect();
	Rect(int x, int y, int w, int h);
	virtual ~Rect();
public:
	int x;
	int y;
	int width;
	int height;
};

#endif
