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
	mData = data;
}

Object* BitTreeNode::getData()
{
	return mData;
}

void BitTreeNode::setLeft(BitTreeNode *left)
{
	mLeft = left;
}

BitTreeNode* BitTreeNode::getLeft()
{
	return mLeft;
}

void BitTreeNode::setRight(BitTreeNode *right)
{
	mRight = right;
}

BitTreeNode* BitTreeNode::getRight()
{
	return mRight;
}
