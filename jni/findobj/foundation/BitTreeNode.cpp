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
		delete mData;
	}
	if(mLeft != NULL) {
		delete mLeft;
	}
	if(mRight != NULL) {
		delete mRight;
	}
}

void BitTreeNode::setData(Object *data)
{
	if(mData != data) {
		delete mData;
	}
	mData = data;
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
	if(mLeft != left) {
		delete mLeft;
	}
	mLeft = left;
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
	if(mRight != right) {
		delete mRight;
	}
	mRight = right;
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
