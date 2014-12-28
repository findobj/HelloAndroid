#ifndef __LINKEDNODE_H__
#define __LINKEDNODE_H__

#include "Object.h"

class LinkedNode : public Object
{
public:
	LinkedNode();
	virtual ~LinkedNode();
public:
	void setData(Object *data);
	Object* getData();

	void setNext(LinkedNode *next);
	LinkedNode* getNext();
	LinkedNode* removeNext();
private:
	Object *mData;
	LinkedNode *mNext;
};

#endif
