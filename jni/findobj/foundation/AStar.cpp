#include "AStar.h"
#include "findobj/Util.h"
#include "findobj/Foundation.h"
#include "Tile.h"

void log_list(List *list)
{
	Log::i("AStar", "log_list start: %d", list->size());
	for(int i = 0; i < list->size(); i++) {
		Tile *tile = (Tile*)list->get(i);
		Log::i("AStar", "log_list tile: %d", tile->index);
	}
	Log::i("AStar", "log_list end");
}

void AStar::test()
{
	Tile *tile1 = new Tile(1);
	Tile *tile2 = new Tile(2);
	Tile *tile3 = new Tile(3);
	Tile *tile4 = new Tile(4);
	Tile *tile5 = new Tile(5);
	List *list = new List();
	list->add(tile1);
	list->add(tile2);
	list->add(tile3);
	list->add(tile4);
	list->add(tile5);
	log_list(list);
	list->remove(4);
	log_list(list);
	list->remove(0);
	log_list(list);
	list->remove(tile3);
	log_list(list);
	list->clear();
	log_list(list);
}

