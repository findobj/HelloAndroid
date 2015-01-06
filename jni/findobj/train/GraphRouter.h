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
private:
	virtual void findRouteInternal(Object *end, ArrayList *listToVisit, ArrayList *listVisited);
	virtual void addToVisited(Object *data, ArrayList *listVisited);
	virtual SearchNode* findNodeInVisited(Object *data, ArrayList *listVisited);
	virtual bool existInVisited(Object *data, ArrayList *listVisited);
private:
	Graph *graph;
};

#endif
