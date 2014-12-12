#ifndef __AB_H__
#define __AB_H__

#include "Object.h"

class AB : public Object
{
public:
	AB();
	AB(Object *a, Object *b);
	virtual ~AB();
public:
	Object *a;
	Object *b;
};

#endif
