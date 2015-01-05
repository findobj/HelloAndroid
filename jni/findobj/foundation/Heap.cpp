#include "Heap.h"
#include "ArrayList.h"

#define heap__macro_pos_left(x) ((x) * 2 + 1)
#define heap__macro_pos_right(x) (((x) + 1) * 2)
#define heap__macro_pos_parent(x) (((x) - 1) / 2)

Heap::Heap(Comparator *comparator)
{
	mList = new ArrayList();
	mComparator = comparator;
	if(mComparator != NULL) {
		mComparator->retain();
	}
}

Heap::~Heap()
{
	if(mList != NULL) {
		mList->release();
	}
	if(mComparator != NULL) {
		mComparator->release();
	}
}

void Heap::insert(Object *data)
{
	if(data == NULL) {
		return;
	}

	mList->add(data);
	heapFyUp(mList->size() - 1);
}

Object* Heap::extract()
{
	if(mList->size() <= 0) {
		return NULL;
	}

	if(mList->size() > 0) {
		mList->swap(0, mList->size() - 1);
	}
	Object *target = mList->get(mList->size() - 1);
	target->retain();
	mList->remove(mList->size() - 1);
	if(mList->size() > 0) {
		heapFyDown(0);
	}
	return target;
}

Object* Heap::peek()
{
	if(mList->size() <= 0) {
		return NULL;
	}
	Object *target = mList->get(0);
	return target;
}

int Heap::size()
{
	return mList->size();
}

ArrayList* Heap::toArrayList()
{
	mList->retain();
	return mList;
}

void Heap::heapFyDown(int position)
{
	if(mComparator == NULL) {
		return ;
	}

	int maxPosition = -1;
	int posLeft = heap__macro_pos_left(position);
	if(posLeft < mList->size()) {
		maxPosition = posLeft;
	}
	int posRight = heap__macro_pos_right(position);
	if(posRight < mList->size()) {
		Object *objLeft = mList->get(posLeft);
		Object *objRight = mList->get(posRight);
		if(mComparator->compare(objRight, objLeft) > 0) {
			maxPosition = posRight;
		}
	}

	if(maxPosition != -1) {
		Object *objCurrent = mList->get(position);
		Object *objMax = mList->get(maxPosition);
		if(mComparator->compare(objMax, objCurrent) > 0) {
			mList->swap(position, maxPosition);
			heapFyDown(maxPosition);
		}
	}
}

void Heap::heapFyUp(int position)
{
	if(mComparator == NULL) {
		return ;
	}
	if(position <= 0) {
		return ;
	}

	int posParent = heap__macro_pos_parent(position);
	Object *objCurrent = mList->get(position);
	Object *objParent = mList->get(posParent);
	if(mComparator->compare(objCurrent, objParent) > 0) {
		mList->swap(position, posParent);
		heapFyUp(posParent);
	}
}


