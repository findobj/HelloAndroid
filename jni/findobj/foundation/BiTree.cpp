#include "BiTree.h"
#include "BiTreeNode.h"

BiTree::BiTree()
{
	mRoot = NULL;
}

BiTree::~BiTree()
{
	if(mRoot != NULL) {
		mRoot->release();
	}
}

void BiTree::setRoot(BiTreeNode *root)
{
	mRoot = root;
}

BiTreeNode* BiTree::getRoot()
{
	return mRoot;
}
