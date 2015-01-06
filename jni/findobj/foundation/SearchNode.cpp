#include "SearchNode.h"

SearchNode::SearchNode()
{
	mData = NULL;
	mParent = NULL;
	mNext = NULL;
	mVisited = false;
	mWeight = 1;
}

SearchNode::~SearchNode()
{
	if(mData != NULL) {
		mData->release();
	}
	if(mNext != NULL) {
		mNext->release();
	}
}

void SearchNode::setData(Object *data)
{
	Object::assign((Object**)&mData, (Object**)&data);
}

Object* SearchNode::getData()
{
	return mData;
}

void SearchNode::setParent(SearchNode *parent)
{
	mParent = parent;
}

SearchNode* SearchNode::getParent()
{
	return mParent;
}

void SearchNode::setNext(SearchNode *next)
{
	mNext = next;
}

SearchNode* SearchNode::getNext()
{
	return mNext;
}

void SearchNode::setVisited(bool visited)
{
	mVisited = visited;
}

bool SearchNode::isVisited()
{
	return mVisited;
}

void SearchNode::setWeight(int weight)
{
	mWeight = weight;
}

int SearchNode::getWeight()
{
	return mWeight;
}

int SearchNode::getWeightFromParent()
{
	return (mWeight + (mParent != NULL ? mParent->getWeightFromParent() : 0));
}
