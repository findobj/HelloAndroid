#include "List.h"
#include <string.h>
#include "findobj/Util.h"

List::List()
{
	mSize = 0;
	mCapacity = Config::GRANULARITY_DEFAULT;
	mArray = new Object*[mCapacity];
	memset(mArray, 0, sizeof(Object*) * mCapacity);
}

List::~List()
{
	for(int i = 0; i < mSize; i++) {
		delete mArray[i];
	}
	delete mArray;
}

void List::add(Object *obj)
{
	if(obj == NULL ||
			contains(obj)) {
		return;
	}
	increase();
	mArray[mSize++] = obj;
}

void List::addAll(List *list)
{
	if(list == NULL ||
			this == list) {
		return ;
	}
	int size = list->size();
	for(int i = 0; i < size; i++) {
		add(list->get(i));
	}
}

Object* List::get(int index)
{
	if(index >= 0 && index < mSize) {
		return mArray[index];
	}
	return NULL;
}

void List::remove(int index)
{
	if(index >= 0 && index < mSize) {
		Object* target = mArray[index];
		if(index < mSize - 1) {
			int remain = mSize - 1 - index;
			Object** tmp = new Object*[remain];
			memset(tmp, 0, sizeof(Object*) * remain);
			memcpy(tmp, mArray + index + 1, sizeof(Object*) * remain);
			memcpy(mArray + index, tmp, sizeof(Object*) * remain);
		}
		mSize--;
		delete target;
		target = NULL;
	}
}

void List::remove(Object *obj)
{
	if(obj == NULL) {
		return ;
	}
	for(int i = 0; i < mSize; i++) {
		if(obj == mArray[i]) {
			remove(i);
			return ;
		}
	}
}

void List::clear()
{
	for(int i = 0; i < mSize; i++) {
		delete mArray[i];
	}
	delete mArray;
	mSize = 0;
	mCapacity = Config::GRANULARITY_DEFAULT;
	mArray = new Object*[mCapacity];
	memset(mArray, 0, sizeof(Object*) * mCapacity);
}

bool List::contains(Object *obj)
{
	if(obj == NULL) {
		return false;
	}

	for(int i = 0; i < mSize; i++) {
		if(obj == mArray[i]) {
			return true;
		}
	}
	return false;
}

int List::size()
{
	return mSize;
}

bool List::isEmpty()
{
	return (0 == mSize);
}

void List::increase()
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

void List::decrease()
{
	if(mSize >= mCapacity / 4) {
		return;
	}
	if(mCapacity <= Config::GRANULARITY_DEFAULT) {
		return;
	}
	mCapacity /= 2;
	Object **tmp = new Object*[mCapacity];
	memset(tmp, 0, sizeof(Object*) * mCapacity);
	memcpy(tmp, mArray, sizeof(Object*) * mSize);
	delete mArray;
	mArray = tmp;
}
