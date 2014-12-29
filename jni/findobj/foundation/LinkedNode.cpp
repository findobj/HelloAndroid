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
	Object::assign((Object**)(&mNext), (Object**)(&next));
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
