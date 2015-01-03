#include "BiTreeNode.h"

BiTreeNode::BiTreeNode()
{
	mData = NULL;
	mLeft = NULL;
	mRight = NULL;
}

BiTreeNode::~BiTreeNode()
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

void BiTreeNode::setData(Object *data)
{
	Object::assign(&mData, &data);
}

Object* BiTreeNode::getData()
{
	return mData;
}

void BiTreeNode::setLeft(BiTreeNode *left)
{
	mLeft = left;
}

BiTreeNode* BiTreeNode::getLeft()
{
	return mLeft;
}

void BiTreeNode::setRight(BiTreeNode *right)
{
	mRight = right;
}

BiTreeNode* BiTreeNode::getRight()
{
	return mRight;
}
