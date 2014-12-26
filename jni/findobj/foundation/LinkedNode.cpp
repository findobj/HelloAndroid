#include "LinkedNode.h"

LinkedNode::LinkedNode()
{
	mData = NULL;
	mNext = NULL;
}

LinkedNode::~LinkedNode()
{
	if(mData != NULL) {
		delete mData;
	}
	if(mNext != NULL) {
		delete mNext;
	}
}

void LinkedNode::setData(Object *data)
{
	if(mData != data) {
		delete mData;
	}
	mData = data;
}

Object* LinkedNode::getData()
{
	return mData;
}

Object* LinkedNode::removeData()
{
	Object *tmp = mData;
	mData = NULL;
	return tmp;
}

void LinkedNode::setNext(LinkedNode *next)
{
	if(mNext != next) {
		delete mNext;
	}
	mNext = next;
}

LinkedNode* LinkedNode::getNext()
{
	return mNext;
}

LinkedNode* LinkedNode::removeNext()
{
	LinkedNode *tmp = mNext;
	mNext = NULL;
	return tmp;
}
