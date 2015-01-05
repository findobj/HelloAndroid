#ifndef __HEAP_H__
#define __HEAP_H__

#include "Object.h"
#include "Comparator.h"

class ArrayList;

class Heap : public Object
{
public:
	Heap(Comparator *comparator);
	virtual ~Heap();
public:
	void insert(Object *data);
	Object* extract();
	Object* peek();
	int size();
	ArrayList* toArrayList();
private:
	void heapFyDown(int position);
	void heapFyUp(int position);
private:
	ArrayList *mList;
	Comparator *mComparator;
};

#endif
