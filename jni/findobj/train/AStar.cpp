#include "AStar.h"
#include "findobj/Util.h"
#include "findobj/Foundation.h"
#include "Tile.h"
#include "findobj/platform/linux/LLog.h"

void print_arraylist(ArrayList *list)
{
	Log::i("arraylist", "print arraylist start(%d", list->size());
	for(int i = 0; i < list->size(); i++) {
		String *s = (String*)list->get(i);
		char *str = s->toCharArray();
		Log::i("arraylist", str);
		delete str;
	}
	Log::i("arraylist", "print arraylist end");
}

void test_arraylist()
{
	ArrayList *list = new ArrayList();
	char *buffer = new char[128];
	for(int i = 0; i < 100; i++) {
		sprintf(buffer, "item %d", i);
		String *s = new String(buffer);
		list->add(s);
		s->release();
	}
//	while(list->size() > 0) {
//		list->remove(0);
//	}
//	print_arraylist(list);
	delete buffer;
	list->release();
}

void print_linkedlist(LinkedList *list)
{
	Log::i("linkedlist", "print linkedlist start(%d", list->size());
	for(int i = 0; i < list->size(); i++) {
		String *s = (String*)list->get(i);
		char *str = s->toCharArray();
		Log::i("linkedlist", str);
		delete str;
	}
	Log::i("linkedlist", "print linkedlist end");
}

void test_linkedlist()
{
	LinkedList *list = new LinkedList();
	char *buffer = new char[128];
	for(int i = 0; i < 100; i++) {
		sprintf(buffer, "item %d", i);
		String *s = new String(buffer);
		list->add(s);
		s->release();
	}
//	while(list->size() > 0) {
//		list->remove(0);
//	}
	list->remove(0);
//	list->remove(1);
//	list->remove(list->size() - 1);
	print_linkedlist(list);
	delete buffer;
	list->release();
}

void AStar::test()
{
	Log::i("AStar", "test start");
//	test_arraylist();
	test_linkedlist();
//	HashMap *hashMap = new HashMap();
//	hashMap->put(new String("abc"), new Tile(1));
//	Tile *tile = (Tile*)hashMap->get(new String("abc"));
//	if(tile != NULL) {
//		Log::i("AStar", "found: %d", tile->index);
//	} else {
//		Log::i("AStar", "not found");
//	}
//	delete hashMap;
	Log::i("AStar", "test end");
}
