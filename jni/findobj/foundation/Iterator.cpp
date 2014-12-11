#include "Iterator.h"
#include <string.h>
#include "findobj/Util.h"

Iterator::Iterator()
{
	mSize = 0;
	mIndex = 0;
	mCapacity = Config::GRANULARITY_DEFAULT;
	mArray = new Object*[mCapacity];
	memset(mArray, 0, sizeof(Object*) * mCapacity);
}

Iterator::~Iterator()
{
	if(mArray != NULL) {
		delete mArray;
	}
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
	if(mSize <= mCapacity * 3 / 4) {
		return ;
	}
	mCapacity *= 2;
	Object **tmp = new Object*[mCapacity];
	memset(tmp, 0, sizeof(Object*) * mCapacity);
	memcpy(tmp, mArray, sizeof(Object*) * mSize);
	delete mArray;
	mArray = tmp;
}
