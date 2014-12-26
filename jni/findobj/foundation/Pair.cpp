#include "Pair.h"

Pair::Pair()
{
}

Pair::Pair(Object *left, Object *right)
{
	mLeft = left;
	mRight = right;
}

Pair::~Pair()
{
	if(mLeft != NULL) {
		delete mLeft;
	}
	if(mRight != NULL) {
		delete mRight;
	}
}

void Pair::setLeft(Object *left)
{
	if(mLeft != left) {
		delete mLeft;
	}
	mLeft = left;
}

Object* Pair::getLeft()
{
	return mLeft;
}

Object* Pair::removeLeft()
{
	Object *tmp = mLeft;
	mLeft = NULL;
	return tmp;
}

void Pair::setRight(Object *right)
{
	if(mRight != right) {
		delete mRight;
	}
	mRight = right;
}

Object* Pair::getRight()
{
	return mRight;
}

Object* Pair::removeRight()
{
	Object *tmp = mRight;
	mRight = NULL;
	return tmp;
}


