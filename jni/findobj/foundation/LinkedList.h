#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Object.h"

class LinkedNode;

class LinkedList : public Object
{
public:
	LinkedList();
	virtual ~LinkedList();
public:
	virtual void add(Object *obj);
	virtual Object* get(int index);
	virtual Object* remove(int index);
	virtual void clear();
	virtual bool contains(Object *obj);
	virtual int size();
	virtual bool isEmpty();
private:
	LinkedNode *mHead;
	int mSize;
};

#endif
