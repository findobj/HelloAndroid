#include "Node.h"

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
	}
	if(mLeft != NULL) {
		delete mLeft;
	}
	if(mRight != NULL) {
		delete mRight;
	}
}

void Node::setData(Object *data)
{
	if(mData != NULL) {
		delete mData;
	}
	mData = data;
}

Object* Node::getData()
{
	return mData;
}

void Node::setLeft(Node *left)
{
	if(mLeft != NULL) {
		delete mLeft;
	}
	mLeft = left;
}

Node* Node::getLeft()
{
	return mLeft;
}

void Node::setRight(Node *right)
{
	if(mRight != NULL) {
		delete mRight;
	}
	mRight = right;
}

Node* Node::getRight()
{
	return mRight;
}
