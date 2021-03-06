#include "LinkedNode.h"

LinkedNode::LinkedNode()
{
	mData = NULL;
	mNext = NULL;
}

LinkedNode::~LinkedNode()
{
	if(mData != NULL) {
		mData->release();
	}
	if(mNext != NULL) {
		mNext->release();
	}
}

void LinkedNode::setData(Object *data)
{
	Object::assign((Object**)(&mData), (Object**)(&data));
}

Object* LinkedNode::getData()
{
	return mData;
}

void LinkedNode::setNext(LinkedNode *next)
{
	mNext = next;
}

LinkedNode* LinkedNode::getNext()
{
	return mNext;
}
