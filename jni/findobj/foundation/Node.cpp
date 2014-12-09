#include "Node.h"
#include <stdio.h>

Node::Node()
{
	mData = NULL;
	mLeft = NULL;
	mRight = NULL;
}

Node::~Node()
{
	if(mData != NULL) {
		delete mData;
		mData = NULL;
	}
	if(mLeft != NULL) {
		delete mLeft;
		mLeft = NULL;
	}
	if(mRight != NULL) {
		delete mRight;
		mRight = NULL;
	}
}

void Node::setData(Object *data)
{
	if(mData != NULL) {
		delete mData;
		mData = NULL;
	}
	mData = data;
}

Object* Node::getData()
{
	return mData;
}

void Node::setLeft(Node *left)
{
	mLeft = left;
}

Node* Node::getLeft()
{
	return mLeft;
}

void Node::setRight(Node *right)
{
	mRight = right;
}

Node* Node::getRight()
{
	return mRight;
}
