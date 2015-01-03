#ifndef __BITREENODE_H__
#define __BITREENODE_H__

#include "Object.h"

class BiTreeNode : public Object
{
public:
	BiTreeNode();
	virtual ~BiTreeNode();
public:
	void setData(Object *data);
	Object* getData();

	void setLeft(BiTreeNode *left);
	BiTreeNode* getLeft();

	void setRight(BiTreeNode *right);
	BiTreeNode* getRight();
private:
	Object *mData;
	BiTreeNode *mLeft;
	BiTreeNode *mRight;
};

#endif
