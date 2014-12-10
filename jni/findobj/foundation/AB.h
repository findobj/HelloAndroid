#ifndef __AB_H__
#define __AB_H__

#include "Object.h"

class AB : public Object
{
public:
	AB();
	AB(void *a, void *b);
public:
	void *a;
	void *b;
};

#endif
