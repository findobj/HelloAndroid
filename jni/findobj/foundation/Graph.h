#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Object.h"

class ArrayList;

class Graph : public Object
{
public:
	Graph();
	virtual ~Graph();
public:
	virtual void insertVertex(Object *vertex);
	virtual void removeVertex(Object *vertex);

	virtual void insertEdge(Object *left, Object *right);
	virtual void removeEdge(Object *left, Object *right);

	virtual bool containsVertex(Object *vertex);
	virtual bool isAdjacent(Object *left, Object *right);

	virtual int sizeOfVertex();
	virtual int sizeOfEdge();

	virtual ArrayList* vertexToList();
private:
	ArrayList *mList;
};

#endif
