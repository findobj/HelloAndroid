#ifndef __PAIR_H__
#define __PAIR_H__

#include "Object.h"

class Pair : public Object
{
public:
	Pair();
	Pair(Object *left, Object *right);
	virtual ~Pair();
public:
	void setLeft(Object *left);
	Object* getLeft();
	Object* removeLeft();

	void setRight(Object *right);
	Object* getRight();
	Object* removeRight();
private:
	Object *mLeft;
	Object *mRight;
};

#endif
