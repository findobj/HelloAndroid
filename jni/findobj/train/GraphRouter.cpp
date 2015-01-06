#include "GraphRouter.h"

GraphRouter::GraphRouter(Graph *graph)
{
	this->graph = graph;
}

GraphRouter::~GraphRouter()
{
}

ArrayList* GraphRouter::findRoute(Object *start, Object *end)
{
	ArrayList *listResult = new ArrayList();
	ArrayList *listToVisit = new ArrayList();
	SearchNode *nodeStart = new SearchNode();
	nodeStart->setData(start);
	listToVisit->add(nodeStart);
	nodeStart->release();
	ArrayList *listVisited = new ArrayList();
	findRouteInternal(end, listToVisit, listVisited);
	bool exist = false;
	for(int i = 0; i < listVisited->size(); i++) {
		SearchNode *node = (SearchNode*)listVisited->get(i);
		if(end->equals(node->getData())) {
			SearchNode *tmp = node;
			while(tmp != NULL) {
				listResult->add(0, tmp);
				tmp = tmp->getParent();
			}
			break;
		}
	}
	return listResult;
}



void GraphRouter::findRouteInternal(Object *end, ArrayList *listToVisit, ArrayList *listVisited)
{
	if(listToVisit->size() <= 0) {
		return;
	}

	for(int i = 0; i < listToVisit->size(); i++) {
		SearchNode *node = (SearchNode*)listToVisit->get(i);
		Tile *tile = (Tile*)node->getData();
		if(tile->equals(end)) {
			if(existInVisited(tile, listVisited)) {
				SearchNode *nodeVisited = findNodeInVisited(tile, listVisited);
				if(node->getWeightFromParent() < nodeVisited->getWeightFromParent()) {
					nodeVisited->setParent(node->getParent());
				}
			} else {
				addToVisited(tile, listVisited);
			}
		} else {

		}
	}

	findRouteInternal(end, listToVisit, listVisited);
}

bool GraphRouter::existInVisited(Object *data, ArrayList *listVisited)
{
	for(int i = 0; i < listVisited->size(); i++) {
		SearchNode *node = (SearchNode*)listVisited->get(i);
		if(data->equals(node->getData())) {
			return true;
		}
	}
	return false;
}
