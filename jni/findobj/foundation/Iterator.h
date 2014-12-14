#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "Object.h"

class ArrayList;

class Iterator : public Object
{
public:
	Iterator();
	virtual ~Iterator();
public:
	virtual bool hasNext();
	virtual Object* next();
	virtual void put(Object *obj);
private:
	ArrayList *list;
	int mIndex;
};

#endif
