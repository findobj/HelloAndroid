#include "Iterator.h"
#include <string.h>

const int Iterator::S_GRANULARITY = 10;

Iterator::Iterator()
{
	mSize = 0;
	mIndex = 0;
	mCapacity = S_GRANULARITY;
	mArray = new Object*[mCapacity];
	memset(mArray, 0, sizeof(Object*) * mCapacity);
}

Iterator::~Iterator()
{
	delete mArray;
}

bool Iterator::hasNext()
{
	return (mIndex < mSize);
}

Object* Iterator::next()
{
	return mArray[mIndex++];
}

void Iterator::put(Object *obj)
{
	if(obj == NULL) {
		return;
	}
	increase();
	mArray[mSize++] = obj;
}

void Iterator::increase()
{
	if(mSize <= mCapacity / 2) {
		return ;
	}
	mCapacity *= 2;
	Object **tmp = new Object*[mCapacity];
	memset(tmp, 0, sizeof(Object*) * mCapacity);
	memcpy(tmp, mArray, sizeof(Object*) * mSize);
	delete mArray;
	mArray = tmp;
}
