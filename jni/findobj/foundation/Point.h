#ifndef __POINT_H__
#define __POINT_H__

#include "Object.h"

class Point : public Object
{
public:
	Point();
	Point(int x, int y);
	virtual ~Point();
public:
	int x;
	int y;
};

#endif
