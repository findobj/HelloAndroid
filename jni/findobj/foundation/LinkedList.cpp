#include "LinkedList.h"
#include "LinkedNode.h"
#include "Constant.h"
#include "findobj/Util.h"

LinkedList::LinkedList()
{
	mHead = NULL;
	mSize = 0;
}

LinkedList::~LinkedList()
{
	if(mHead != NULL) {
		mHead->release();
	}
}

void LinkedList::add(Object *obj)
{
	if(obj == NULL) {
		return;
	}
	LinkedNode *node = new LinkedNode();
	node->setData(obj);
	if(mHead == NULL) {
		mHead = node;
	} else {
		LinkedNode *last = mHead;
		while(last->getNext() != NULL) {
			last = last->getNext();
		}
		last->setNext(node);
	}
	mSize++;
}

Object* LinkedList::get(int index)
{
	Object *target = NULL;
	if(index >= 0 && index < mSize) {
		LinkedNode *node = mHead;
		while(index > 0) {
			node = node->getNext();
			index--;
		}
		target = node->getData();
	}
	return target;
}

void LinkedList::remove(int index)
{
	if(index >= 0 && index < mSize) {
		LinkedNode *node = NULL;
		if(index == 0) {
			node = mHead;
			mHead = mHead->getNext();
		} else {
			LinkedNode *prevNode = NULL;
			LinkedNode *node = mHead;
			while(index > 0) {
				prevNode = node;
				node = node->getNext();
				index--;
			}
			prevNode->setNext(node->getNext());
			node->removeNext();
		}
		node->release();
		mSize--;
	}
}

void LinkedList::clear()
{
	if(mHead != NULL) {
		mHead->release();
	}
	mHead = NULL;
	mSize = 0;
}

bool LinkedList::contains(Object *obj)
{
	if(obj == NULL) {
		return false;
	}

	for(int i = 0; i < mSize; i++) {
		if(obj == get(i)) {
			return true;
		}
	}
	return false;
}

int LinkedList::size()
{
	return mSize;
}

bool LinkedList::isEmpty()
{
	return (0 == mSize);
}

