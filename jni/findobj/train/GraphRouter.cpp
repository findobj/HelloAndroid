#include "GraphRouter.h"
#include "findobj/Util.h"
#include "Tile.h"

class FindRouteFrame : public Object
{
public:
	GraphRouter *graphRouter;
	Object *end;
	int jumpStep;
};

bool funcLoopForFindRouteInternal(GraphRouter *graphRouter, Object *end)
{
	Log::i("funcLoop", "funcLoopForFindRouteInternal start");
	bool result = false;

	Stack *funcStack = new Stack();
	FindRouteFrame *frameFirst = new FindRouteFrame();
	frameFirst->graphRouter = graphRouter;
	frameFirst->end = end;
	frameFirst->jumpStep = 0;
	funcStack->push(frameFirst);
	frameFirst->release();

	while(funcStack->size() > 0) {
		FindRouteFrame *frame = (FindRouteFrame*)funcStack->pop();

		if(0 == frame->jumpStep) {
			if(frame->graphRouter->getOpenList()->size() <= 0) {
				frame->release();
				continue;
			}

			SearchNode *node = frame->graphRouter->findBestFromOpenList(end);
			if(node == NULL) {
				frame->release();
				continue;
			}

			Tile *tile = (Tile*)node->getData();
			if(tile->equals(end)) {
				frame->release();
				continue;
			}

			node->retain();
			frame->graphRouter->removeFromOpenList(node->getData());
			frame->graphRouter->addToCloseList(node->getData());
			frame->graphRouter->addAdjToOpenList(node, end);
		//	node->release();

			frame->jumpStep = 1;

			FindRouteFrame *frameNext = new FindRouteFrame();
			frameNext->graphRouter = graphRouter;
			frameNext->end = end;
			frameNext->jumpStep = 0;
			funcStack->push(frameNext);
			continue;
		} else if(1 == frame->jumpStep) {
			frame->release();
		}
	}

	return result;
}

GraphRouter::GraphRouter(Graph *graph)
{
	this->graph = graph;
	listOpen = new ArrayList();
	listClose = new ArrayList();
}

GraphRouter::~GraphRouter()
{
	if(listOpen != NULL) {
		listOpen->release();
	}
	if(listClose != NULL) {
		listClose->release();
	}
}

ArrayList* GraphRouter::findRoute(Object *start, Object *end)
{
	ArrayList *listResult = new ArrayList();
	listOpen->clear();
	listClose->clear();

	if(graph->containsVertex(start)) {
		addToOpenList(start, NULL);
		findRouteInternal(end);
//		funcLoopForFindRouteInternal(this, end);
		SearchNode *node = getFromOpenList(end);
		while(node != NULL) {
			listResult->add(0, node->getData());
			node = node->getParent();
		}
	}

	return listResult;
}


bool GraphRouter::findRouteInternal(Object *end)
{
	if(listOpen->size() <= 0) {
		return false;
	}

	SearchNode *node = findBestFromOpenList(end);
	if(node == NULL) {
		return false;
	}

	Tile *tile = (Tile*)node->getData();
	if(tile->equals(end)) {
		return true;
	}

	node->retain();
	removeFromOpenList(node->getData());
	addToCloseList(node->getData());
	addAdjToOpenList(node, end);
//	node->release();

	return findRouteInternal(end);
}

void GraphRouter::addAdjToOpenList(SearchNode *node, Object *end)
{
	LinkedList* adjList = graph->adjToList(node->getData());
	if(adjList->size() > 0) {
		for(int i = 0; i < adjList->size(); i++) {
			Object *adjData = adjList->get(i);
			if(containsInCloseList(adjData)) {
				continue;
			}

			if(containsInOpenList(adjData)) {
				SearchNode *nodeOpen = getFromOpenList(adjData);
				int oldG = getG(nodeOpen);
				int newG = getG(node) + nodeOpen->getWeight();
				if(newG < oldG) {
					node->retain();
					nodeOpen->setParent(node);
				}
			} else {
				addToOpenList(adjData, node);
			}
		}
	}
}

SearchNode* GraphRouter::findBestFromOpenList(Object *end)
{
	SearchNode *result = NULL;
	for(int i = 0; i < listOpen->size(); i++) {
		SearchNode *node = (SearchNode*)listOpen->get(i);
		if(result == NULL) {
			result = node;
		} else if(getF(node, end) <= getF(result, end)) {
			result = node;
		}
	}
	return result;
}

void GraphRouter::addToOpenList(Object *data, SearchNode *parent)
{
	SearchNode *node = new SearchNode();
	node->setData(data);
	node->setParent(parent);
	listOpen->add(node);
}

SearchNode* GraphRouter::getFromOpenList(Object *data)
{
	for(int i = 0; i < listOpen->size(); i++) {
		SearchNode *node = (SearchNode*)listOpen->get(i);
		if(data->equals(node->getData())) {
			return node;
		}
	}
	return NULL;
}

void GraphRouter::removeFromOpenList(Object *data)
{
	for(int i = 0; i < listOpen->size(); i++) {
		SearchNode *node = (SearchNode*)listOpen->get(i);
		if(data->equals(node->getData())) {
			listOpen->remove(i);
			break;
		}
	}
}

bool GraphRouter::containsInOpenList(Object *data)
{
	for(int i = 0; i < listOpen->size(); i++) {
		SearchNode *node = (SearchNode*)listOpen->get(i);
		if(data->equals(node->getData())) {
			return true;
		}
	}
	return false;
}

void GraphRouter::addToCloseList(Object *data)
{
	listClose->add(data);
}

bool GraphRouter::containsInCloseList(Object *data)
{
	return listClose->contains(data);
}

int GraphRouter::getF(SearchNode *node, Object *end)
{
	return getG(node) + getH(node->getData(), end);
}

int GraphRouter::getG(SearchNode *node)
{
	return node->getWeightFromParent();
}

int GraphRouter::getH(Object *start, Object *end)
{
	Tile *tileStart = (Tile*)start;
	Tile *tileEnd = (Tile*)end;
	int h = myAbs(tileStart->x - tileEnd->x) +
			myAbs(tileStart->y - tileEnd->y);
	return h;
}

int GraphRouter::myAbs(int value)
{
	return (value >= 0 ? value : -value);
}

ArrayList* GraphRouter::getOpenList()
{
	return listOpen;
}

ArrayList* GraphRouter::getCloseList()
{
	return listClose;
}


