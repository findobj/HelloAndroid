#include "AStar.h"
#include "findobj/Util.h"
#include "findobj/Foundation.h"
#include "Tile.h"
#include "findobj/platform/linux/LLog.h"

void AStar::test()
{
	Log::i("AStar", "test start");
	HashMap *hashMap = new HashMap();
	hashMap->put(new String("abc"), new Tile(1));
	Tile *tile = (Tile*)hashMap->get(new String("abc"));
	if(tile != NULL) {
		Log::i("AStar", "found: %d", tile->index);
	} else {
		Log::i("AStar", "not found");
	}
	delete hashMap;
	Log::i("AStar", "test end");
}
