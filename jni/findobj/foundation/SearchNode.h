#ifndef __SEARCHNODE_H__
#define __SEARCHNODE_H__

#include "Object.h"

class SearchNode : public Object
{
public:
	SearchNode();
	virtual ~SearchNode();
public:
	void setData(Object *data);
	Object* getData();

	void setParent(SearchNode *parent);
	SearchNode* getParent();

	void setNext(SearchNode *next);
	SearchNode* getNext();

	void setVisited(bool visited);
	bool isVisited();

	void setWeight(int weight);
	int getWeight();
	int getWeightFromParent();
private:
	Object *mData;
	SearchNode *mParent;
	SearchNode *mNext;
	bool mVisited;
	int mWeight;
};

#endif
