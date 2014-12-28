#include "BitTreeNode.h"

BitTreeNode::BitTreeNode()
{
	mData = NULL;
	mLeft = NULL;
	mRight = NULL;
}

BitTreeNode::~BitTreeNode()
{
	if(mData != NULL) {
		mData->release();
	}
	if(mLeft != NULL) {
		mLeft->release();
	}
	if(mRight != NULL) {
		mRight->release();
	}
}

void BitTreeNode::setData(Object *data)
{
	Object::assign(&mData, &data);
}

Object* BitTreeNode::getData()
{
	return mData;
}

Object* BitTreeNode::removeData()
{
	Object *tmp = mData;
	mData = NULL;
	return tmp;
}

void BitTreeNode::setLeft(BitTreeNode *left)
{
	Object::assign((Object**)(&mLeft), (Object**)(&left));
}

BitTreeNode* BitTreeNode::getLeft()
{
	return mLeft;
}

BitTreeNode* BitTreeNode::removeLeft()
{
	BitTreeNode *tmp = mLeft;
	mLeft = NULL;
	return tmp;
}

void BitTreeNode::setRight(BitTreeNode *right)
{
	Object::assign((Object**)(&mRight), (Object**)(&right));
}

BitTreeNode* BitTreeNode::getRight()
{
	return mRight;
}

BitTreeNode* BitTreeNode::removeRight()
{
	BitTreeNode *tmp = mRight;
	mRight = NULL;
	return tmp;
}
