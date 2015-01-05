#include "Pair.h"

Pair::Pair()
{
	mLeft = NULL;
	mRight = NULL;
}

Pair::Pair(Object *left, Object *right)
{
	mLeft = NULL;
	mRight = NULL;
	setLeft(left);
	setRight(right);
}

Pair::~Pair()
{
	if(mLeft != NULL) {
		mLeft->release();
	}
	if(mRight != NULL) {
		mRight->release();
	}
}

void Pair::setLeft(Object *left)
{
	Object::assign((Object**)(&mLeft), (Object**)(&left));
}

Object* Pair::getLeft()
{
	return mLeft;
}

void Pair::setRight(Object *right)
{
	Object::assign((Object**)(&mRight), (Object**)(&right));
}

Object* Pair::getRight()
{
	return mRight;
}


