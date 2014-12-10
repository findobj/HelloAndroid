#ifndef __NODE_H__
#define __NODE_H__

#include "Object.h"

class Node : public Object
{
public:
	Node();
	virtual ~Node();
public:
	void setData(Object *data);
	Object* getData();

	void setLeft(Node *left);
	Node* getLeft();

	void setRight(Node *right);
	Node* getRight();
private:
	Object *mData;
	Node *mLeft;
	Node *mRight;
};

#endif
