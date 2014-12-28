#include "Iterator.h"

Iterator::Iterator(ArrayList *list)
{
	mSize = 0;
	mIndex = 0;
	mList = list;
	if(mList != NULL) {
		mList->retain();
		mSize = mList->size();
	}
}

Iterator::~Iterator()
{
	if(mList != NULL) {
		mList->release();
	}
}

bool Iterator::hasNext()
{
	return (mIndex < mSize);
}

Object* Iterator::next()
{
	return mList->get(mIndex++);
}

