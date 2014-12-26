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
	Object* removeData();

	void setLeft(BitTreeNode *left);
	BitTreeNode* getLeft();
	BitTreeNode* removeLeft();

	void setRight(BitTreeNode *right);
	BitTreeNode* getRight();
	BitTreeNode* removeRight();
private:
	Object *mData;
	BitTreeNode *mLeft;
	BitTreeNode *mRight;
};

#endif
