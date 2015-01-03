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

void AStar::test()
{
	Log::i("AStar", "lih test start");
//	test_arraylist();
//	test_linkedlist();
//	test_hashmap();
//	test_bitree();
	Log::i("AStar", "lih test end");
}
