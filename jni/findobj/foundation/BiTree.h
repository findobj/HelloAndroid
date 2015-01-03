#ifndef __BITREE_H__
#define __BITREE_H__

#include "Object.h"

class BiTreeNode;

class BiTree : public Object
{
public:
	BiTree();
	virtual ~BiTree();
public:
	void setRoot(BiTreeNode *root);
	BiTreeNode* getRoot();
private:
	BiTreeNode *mRoot;
};

#endif
