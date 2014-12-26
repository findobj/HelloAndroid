#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "Object.h"
#include "ArrayList.h"

class Iterator : public Object
{
public:
	Iterator(ArrayList *list);
	virtual ~Iterator();
public:
	virtual bool hasNext();
	virtual Object* next();
private:
	ArrayList *mList;
	int mSize;
	int mIndex;
};

#endif
