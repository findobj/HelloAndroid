#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "Object.h"

class ArrayList;

class Queue : public Object
{
public:
	Queue();
	virtual ~Queue();
public:
	virtual void enqueue(Object *data);
	virtual Object* dequeue();
	virtual Object* peek();
	virtual int size();
public:
	ArrayList *mList;
};

#endif
