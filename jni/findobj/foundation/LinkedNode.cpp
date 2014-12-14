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
	if(mData != NULL) {
		delete mData;
	}
	mData = data;
}

Object* LinkedNode::getData()
{
	return mData;
}

void LinkedNode::setNext(LinkedNode *next)
{
	if(mNext != NULL) {
		delete mNext;
	}
	mNext = next;
}

LinkedNode* LinkedNode::getNext()
{
	return mNext;
}
