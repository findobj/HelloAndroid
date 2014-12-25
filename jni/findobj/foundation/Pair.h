#ifndef __PAIR_H__
#define __PAIR_H__

#include "Object.h"

class Pair : public Object
{
public:
	Pair();
	Pair(Object *left, Object *right);
	virtual ~Pair();
public:
	Object *left;
	Object *right;
};

#endif
