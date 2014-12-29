#include "ArrayList.h"
#include "Constant.h"
#include "findobj/Util.h"

ArrayList::ArrayList()
{
	mSize = 0;
	mCapacity = DEFAULT_SIZE_GRANULARITY;
	mArray = new Object*[mCapacity];
	memset(mArray, 0, sizeof(Object*) * mCapacity);
}

ArrayList::~ArrayList()
{
	for(int i = 0; i < mSize; i++) {
		mArray[i]->release();
	}
	delete mArray;
}

void ArrayList::add(Object *obj)
{
	if(obj == NULL) {
		return ;
	}
	increase();
	obj->retain();
	mArray[mSize++] = obj;
}

void ArrayList::addAll(ArrayList *list)
{
	if(list == NULL) {
		return ;
	}
	int size = list->size();
	for(int i = 0; i < size; i++) {
		add(list->get(i));
	}
}

Object* ArrayList::get(int index)
{
	if(index >= 0 && index < mSize) {
		return mArray[index];
	}
	return NULL;
}

void ArrayList::remove(int index)
{
	if(index >= 0 && index < mSize) {
		Object *target = mArray[index];
		target->release();
		if(index < mSize - 1) {
			int remain = mSize - 1 - index;
			Object** tmp = new Object*[remain];
			memset(tmp, 0, sizeof(Object*) * remain);
			memcpy(tmp, mArray + index + 1, sizeof(Object*) * remain);
			memcpy(mArray + index, tmp, sizeof(Object*) * remain);
			delete tmp;
		}
		mSize--;

		decrease();
	}
}

void ArrayList::clear()
{
	for(int i = 0; i < mSize; i++) {
		mArray[i]->release();
	}
	delete mArray;
	mSize = 0;
	mCapacity = DEFAULT_SIZE_GRANULARITY;
	mArray = new Object*[mCapacity];
	memset(mArray, 0, sizeof(Object*) * mCapacity);
}

bool ArrayList::contains(Object *obj)
{
	for(int i = 0; i < mSize; i++) {
		if(obj == mArray[i]) {
			return true;
		}
	}
	return false;
}

int ArrayList::size()
{
	return mSize;
}

bool ArrayList::isEmpty()
{
	return (0 == mSize);
}

void ArrayList::sort(Comparator *comparator)
{

}

void ArrayList::increase()
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

void ArrayList::decrease()
{
	if(mSize >= mCapacity / 4) {
		return;
	}
	if(mCapacity <= DEFAULT_SIZE_GRANULARITY) {
		return;
	}
	mCapacity /= 2;
	Object **tmp = new Object*[mCapacity];
	memset(tmp, 0, sizeof(Object*) * mCapacity);
	memcpy(tmp, mArray, sizeof(Object*) * mSize);
	delete mArray;
	mArray = tmp;
}
