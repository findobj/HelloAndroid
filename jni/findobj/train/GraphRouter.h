#ifndef __GRAPHROUTER_H__
#define __GRAPHROUTER_H__

#include "findobj/Foundation.h"

class GraphRouter
{
public:
	GraphRouter(Graph *graph);
	virtual ~GraphRouter();
public:
	virtual ArrayList* findRoute(Object *start, Object *end);
public:
	virtual SearchNode* findBestFromOpenList(Object *end);
	virtual void addToOpenList(Object *data, SearchNode *parent);
	virtual SearchNode* getFromOpenList(Object *data);
	virtual void removeFromOpenList(Object *data);
	virtual bool containsInOpenList(Object *data);
	virtual void addToCloseList(Object *data);
	virtual bool containsInCloseList(Object *data);
	virtual void addAdjToOpenList(SearchNode *node, Object *end);
	virtual int getF(SearchNode *node, Object *end);
	virtual int getG(SearchNode *node);
	virtual int getH(Object *start, Object *end);
	virtual int myAbs(int value);
	virtual ArrayList* getOpenList();
	virtual ArrayList* getCloseList();
private:
	virtual bool findRouteInternal(Object *end);
private:
	Graph *graph;
	ArrayList *listOpen;
	ArrayList *listClose;
};

#endif
