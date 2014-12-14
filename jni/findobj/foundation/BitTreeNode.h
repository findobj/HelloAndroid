#ifndef __BITTREENODE_H__
#define __BITTREENODE_H__

#include "Object.h"

class BitTreeNode : public Object
{
public:
	BitTreeNode();
	virtual ~BitTreeNode();
public:
	void setData(Object *data);
	Object* getData();

	void setLeft(BitTreeNode *left);
	BitTreeNode* getLeft();

	void setRight(BitTreeNode *right);
	BitTreeNode* getRight();
private:
	Object *mData;
	BitTreeNode *mLeft;
	BitTreeNode *mRight;
};

#endif
