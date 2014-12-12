#ifndef __LIST_H__
#define __LIST_H__

#include "Object.h"

class List : public Object
{
public:
	List();
	List(int granularity);
	virtual ~List();
public:
	virtual void add(Object *obj);
	virtual void addAll(List *list);
	virtual Object* get(int index);
	virtual void remove(int index);
	virtual void remove(Object *obj);
	virtual void clear();
	virtual bool contains(Object *obj);
	virtual int size();
	virtual bool isEmpty();
protected:
	virtual void increase();
	virtual void decrease();
private:
	Object **mArray;
	int mSize;
	int mCapacity;
};

#endif
