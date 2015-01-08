#ifndef __STACK_H__
#define __STACK_H__

#include "Object.h"

class ArrayList;

class Stack : public Object
{
public:
	Stack();
	virtual ~Stack();
public:
	virtual void push(Object *data);
	virtual Object* pop();
	virtual Object* peek();
	virtual int size();
public:
	ArrayList *mList;
};

#endif
