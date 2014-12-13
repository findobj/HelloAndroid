#ifndef __COMPARATOR_H__
#define __COMPARATOR_H__

#include "Object.h"

class Comparator : public Object
{
public:
	virtual int compare(Object *left, Object *right) = 0;
};

#endif
