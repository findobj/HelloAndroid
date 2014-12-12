#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "Object.h"

class Iterator : public Object
{
public:
	Iterator();
	virtual ~Iterator();
public:
	virtual bool hasNext();
	virtual Object* next();
	virtual void put(Object *obj);
protected:
	virtual void increase();
private:
	Object **mArray;
	int mSize;
	int mIndex;
	int mCapacity;
};

#endif
