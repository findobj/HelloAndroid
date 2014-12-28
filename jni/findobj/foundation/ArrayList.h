#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include "Object.h"
#include "Comparator.h"

class ArrayList : public Object
{
public:
	ArrayList();
	virtual ~ArrayList();
public:
	virtual void add(Object *obj);
	virtual void addAll(ArrayList *list);
	virtual Object* get(int index);
	virtual void remove(int index);
	virtual void clear();
	virtual bool contains(Object *obj);
	virtual int size();
	virtual bool isEmpty();
	virtual void sort(Comparator *comparator);
protected:
	virtual void increase();
	virtual void decrease();
private:
	Object **mArray;
	int mSize;
	int mCapacity;
};

#endif
