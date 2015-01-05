#include "Graph.h"
#include "Pair.h"
#include "ArrayList.h"
#include "LinkedList.h"

Graph::Graph()
{
	mList = new ArrayList();
}

Graph::~Graph()
{
	if(mList != NULL) {
		mList->release();
	}
}

void Graph::insertVertex(Object *vertex)
{
	if(vertex == NULL) {
		return ;
	}
	if(containsVertex(vertex)) {
		return ;
	}

	LinkedList *adjList = new LinkedList();
	Pair *pair = new Pair(vertex, adjList);
	mList->add(pair);

	pair->release();
	adjList->release();
}

void Graph::removeVertex(Object *vertex)
{
	if(vertex == NULL) {
		return ;
	}

	for(int i = 0; i < mList->size(); i++) {
		Pair *pair = (Pair*)mList->get(i);
		if(vertex->equals(pair->getLeft())) {
			mList->remove(i);
			break;
		}
	}
}

void Graph::insertEdge(Object *left, Object *right)
{
	if(left == NULL ||
			right == NULL) {
		return ;
	}
	if(!containsVertex(left) ||
			!containsVertex(right)) {
		return ;
	}

	for(int i = 0; i < mList->size(); i++) {
		Pair *pair = (Pair*)mList->get(i);
		if(left->equals(pair->getLeft())) {
			LinkedList *adjList = (LinkedList*)pair->getRight();
			if(!adjList->contains(right)) {
				adjList->add(right);
			}
			break;
		}
	}
}

void Graph::removeEdge(Object *left, Object *right)
{
	if(left == NULL ||
			right == NULL) {
		return ;
	}

	for(int i = 0; i < mList->size(); i++) {
		Pair *pair = (Pair*)mList->get(i);
		if(left->equals(pair->getLeft())) {
			LinkedList *adjList = (LinkedList*)pair->getRight();
			adjList->remove(right);
			break;
		}
	}
}

bool Graph::containsVertex(Object *vertex)
{
	if(vertex == NULL) {
		return false;
	}

	for(int i = 0; i < mList->size(); i++) {
		Pair *pair = (Pair*)mList->get(i);
		if(vertex->equals(pair->getLeft())) {
			return true;
		}
	}
	return false;
}

bool Graph::isAdjacent(Object *left, Object *right)
{
	if(left == NULL ||
			right == NULL) {
		return false;
	}

	for(int i = 0; i < mList->size(); i++) {
		Pair *pair = (Pair*)mList->get(i);
		if(left->equals(pair->getLeft())) {
			LinkedList *adjList = (LinkedList*)pair->getRight();
			if(adjList->contains(right)) {
				return true;
			} else {
				return false;
			}
		}
	}
	return false;
}

int Graph::sizeOfVertex()
{
	return mList->size();
}

int Graph::sizeOfEdge()
{
	int size = 0;
	for(int i = 0; i < mList->size(); i++) {
		Pair *pair = (Pair*)mList->get(i);
		LinkedList *adjList = (LinkedList*)pair->getRight();
		size += adjList->size();
	}
	return size;
}

ArrayList* Graph::vertexToList()
{
	ArrayList *vertexList = new ArrayList();
	for(int i = 0; i < mList->size(); i++) {
		Pair *pair = (Pair*)mList->get(i);
		vertexList->add(pair->getLeft());
	}
	return vertexList;
}

