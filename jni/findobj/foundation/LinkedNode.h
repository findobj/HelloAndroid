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

	void setNext(Node *next);
	LinkedNode* getNext();
private:
	Object *mData;
	LinkedNode *mNext;
};

#endif
