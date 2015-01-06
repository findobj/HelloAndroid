#include "AStar.h"
#include "findobj/Util.h"
#include "findobj/Foundation.h"
#include "Tile.h"
#include "GraphRouter.h"

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
	list->remove(0);
	list->remove(20);
	list->remove(list->size() - 1);
	print_arraylist(list);
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
	while(list->size() > 0) {
		list->remove(list->size() - 1);
	}
//	list->remove(0);
//	list->remove(20);
//	list->remove(list->size() - 1);
	print_linkedlist(list);
	delete buffer;
	list->release();
}

void test_hashmap()
{
	HashMap *hashMap = new HashMap();
	int len = 1024;
	char *buffer = new char[128];
	for(int i = 0; i < len; i++) {
		sprintf(buffer, "item %d", i);
		String *s = new String(buffer);
		Tile *tile = new Tile(i);
		hashMap->put(s, tile);
		s->release();
		tile->release();
	}
	String *s = new String("item 5");
	Tile *tile = (Tile*)hashMap->get(s);
	if(tile != NULL) {
		Log::i("test_hashmap", "lih contains item 5: %d", tile->index);
	} else {
		Log::i("test_hashmap", "lih contains item 5 not");
	}
	s->release();
//	Log::i("test_hashmap", "lih print hashmap before(%d", hashMap->size());
//	for(int i = len - 1; i >= 0; i--) {
//		sprintf(buffer, "item %d", i);
//		String *s = new String(buffer);
//		if(!hashMap->containsKey(s)) {
//			Log::i("test_hashmap", "lih containsKey not: %s", s->toCharArray());
//		}
//		hashMap->remove(s);
//		s->release();
//	}
//	Log::i("test_hashmap", "lih print hashmap after(%d", hashMap->size());
	hashMap->release();
	delete buffer;
}

void print_bitree_node(BiTreeNode *node)
{
	if(node != NULL) {
		String *s = (String*)node->getData();
		if(s != NULL) {
			const char *str = s->toCharArray();
			Log::i("BiTree", "print BiTree node: %s", str);
			delete str;
		} else {
			Log::i("BiTree", "print BiTree node is null");
		}
		print_bitree_node(node->getLeft());
		print_bitree_node(node->getRight());
	}
}

void print_bitree(BiTree *tree)
{
	Log::i("BiTree", "print BiTree start");
	print_bitree_node(tree->getRoot());
	Log::i("BiTree", "print BiTree end");
}

void test_bitree()
{
	BiTree *tree = new BiTree();
	BiTreeNode *root = new BiTreeNode();
	String *s_root = new String("root");
	root->setData(s_root);
	s_root->release();
	BiTreeNode *left = new BiTreeNode();
	String *s_left = new String("left");
	left->setData(s_left);
	s_left->release();
	BiTreeNode *right = new BiTreeNode();
	String *s_right = new String("right");
	right->setData(s_right);
	s_right->release();
	root->setLeft(left);
	root->setRight(right);
	tree->setRoot(root);
	print_bitree(tree);
	tree->release();
}

class TileComparator : public Comparator
{
public:
	int compare(Object *left, Object *right)
	{
		Tile *tileLeft = (Tile*)left;
		Tile *tileRight = (Tile*)right;
		return (tileLeft->index - tileRight->index);
	}
};

void print_heap(Heap *heap)
{
	ArrayList *list = heap->toArrayList();
	Log::i("heap", "print heap start(%d", list->size());
	for(int i = 0; i < list->size(); i++) {
		Tile *t = (Tile*)list->get(i);
		Log::i("tile", "tile %d", t->index);
	}
	list->release();
	Log::i("heap", "print heap end");
}

void test_heap()
{
	Log::i("AStar", "test_heap start");
	TileComparator *tileComparator = new TileComparator();
	Heap *heap = new Heap(tileComparator);
	Tile *tile = new Tile(5);
	heap->insert(tile);
	tile->release();
	tile = new Tile(2);
	heap->insert(tile);
	tile->release();
	tile = new Tile(6);
	heap->insert(tile);
	tile->release();
	tile = new Tile(3);
	heap->insert(tile);
	tile->release();
	tile = new Tile(7);
	heap->insert(tile);
	tile->release();
	print_heap(heap);
	tile = (Tile*)heap->extract();
	Log::i("tile", "extract tile %d", tile->index);
	tile->release();
	tile = new Tile(1);
	heap->insert(tile);
	tile->release();
	print_heap(heap);
	tileComparator->release();
	heap->release();
	Log::i("AStar", "test_heap end");
}

void test_graph()
{
	Log::i("AStar", "test_graph start");
	Graph *graph = new Graph();
	Tile *tile1 = new Tile(1);
	Tile *tile2 = new Tile(2);
	graph->insertVertex(tile1);
	graph->insertVertex(tile2);
	graph->insertEdge(tile1, tile2);
	if(graph->isAdjacent(tile1, tile2)) {
		Log::i("AStar", "isAdjacent(1-2) true");
	} else {
		Log::i("AStar", "isAdjacent(1-2) false");
	}
	if(graph->isAdjacent(tile2, tile1)) {
		Log::i("AStar", "isAdjacent(2-1) true");
	} else {
		Log::i("AStar", "isAdjacent(2-1) false");
	}
	graph->insertEdge(tile2, tile1);
	if(graph->isAdjacent(tile1, tile2)) {
		Log::i("AStar", "isAdjacent(1-2) true");
	} else {
		Log::i("AStar", "isAdjacent(1-2) false");
	}
	if(graph->isAdjacent(tile2, tile1)) {
		Log::i("AStar", "isAdjacent(2-1) true");
	} else {
		Log::i("AStar", "isAdjacent(2-1) false");
	}
	tile1->release();
	tile2->release();
	graph->release();
	Log::i("AStar", "test_graph end");
}

void test_maze()
{
	Log::i("AStar", "test_maze start");
	Graph *graph = new Graph();
	int row = 10;
	int column = 10;
	int tiles[row][column] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
			1, 0, 1, 0, 1, 0, 1, 1, 1, 1,
			1, 0, 1, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 1, 0, 1, 1, 1, 1, 0, 1,
			1, 0, 0, 0, 1, 1, 0, 1, 0, 1,
			1, 1, 0, 1, 0, 0, 0, 1, 0, 1,
			1, 1, 1, 0, 0, 1, 0, 1, 0, 1,
			1, 0, 0, 0, 1, 1, 0, 0, 0, 1,
			1, 0, 1, 1, 1, 1, 1, 1, 1, 1
	};
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			Tile* tile = new Tile(i, j);
			tile->state = tiles[i][j];
			graph->insertVertex(tile);
			tile->release();
		}
	}
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			Tile* tile = new Tile(i, j);
			Tile *tmp = NULL;
			if(j > 0 &&
					tiles[i][j - 1] == 0) {
				tmp = new Tile(i, j - 1);
				graph->insertEdge(tile, tmp);
			}
			if(j < column - 1 &&
					tiles[i][j + 1] == 0) {
				tmp = new Tile(i, j + 1);
				graph->insertEdge(tile, tmp);
			}
			if(i > 0 &&
					tiles[i - 1][j] == 0) {
				tmp = new Tile(i - 1, j);
				graph->insertEdge(tile, tmp);
			}
			if(i < row - 1 &&
					tiles[i + 1][j] == 0) {
				tmp = new Tile(i + 1, j);
				graph->insertEdge(tile, tmp);
			}
		}
	}

	GraphRouter *router = new GraphRouter(graph);
	Tile *tileStart = new Tile(1, 1);
	Tile *tileEnd = new Tile(9, 1);
	ArrayList *list = router->findRoute(tileStart, tileEnd);
	if(list != NULL) {
		Log::i("AStar", "findRoute succed");
	} else {
		Log::i("AStar", "findRoute failed");
	}
	list->release();
	tileStart->release();
	tileEnd->release();
	graph->release();
	Log::i("AStar", "test_maze end");
}

void AStar::test()
{
	Log::i("AStar", "test start");
//	test_arraylist();
//	test_linkedlist();
//	test_hashmap();
//	test_bitree();
//	test_heap();
//	test_graph();
	test_maze();
	Log::i("AStar", "test end");
}
