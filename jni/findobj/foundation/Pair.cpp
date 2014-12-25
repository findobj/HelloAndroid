#include "Pair.h"

Pair::Pair()
{
}

Pair::Pair(Object *left, Object *right)
{
	this->left = left;
	this->right = right;
}

Pair::~Pair()
{
	if(left != NULL) {
		delete left;
	}
	if(right != NULL) {
		delete right;
	}
}

