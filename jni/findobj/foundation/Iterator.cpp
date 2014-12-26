#include "Iterator.h"

Iterator::Iterator(ArrayList *list)
{
	mSize = 0;
	mIndex = 0;
	mList = list;
	if(mList != NULL) {
		mSize = mList->size();
	}
}

Iterator::~Iterator()
{
}

bool Iterator::hasNext()
{
	return (mIndex < mSize);
}

Object* Iterator::next()
{
	return mList->get(mIndex++);
}

