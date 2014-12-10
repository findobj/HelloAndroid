#ifndef __SIZE_H__
#define __SIZE_H__

#include "Object.h"

class Size : public Object
{
public:
	Size();
	Size(int w, int h);
	virtual ~Size();
public:
	int width;
	int height;
};

#endif
