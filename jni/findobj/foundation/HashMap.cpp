#include "HashMap.h"
#include "Constant.h"
#include "LinkedList.h"
#include "Pair.h"
#include "Iterator.h"
#include "findobj/Util.h"

HashMap::HashMap()
{
	mSize = 0;
	mBucketSize = DEFAULT_SIZE_GRANULARITY;
	mBuckets = new LinkedList*[mBucketSize];
	memset(mBuckets, 0, sizeof(LinkedList*) * mBucketSize);
}

HashMap::~HashMap()
{
	for(int i = 0; i < mBucketSize; i++) {
		LinkedList* bucket = mBuckets[i];
		if(bucket != NULL) {
			delete bucket;
		}
	}
	delete mBuckets;
}

void HashMap::put(Object *key, Object *value)
{
	if(key == NULL ||
			value == NULL) {
		return ;
	}
	if(containsKey(key)) {
		return ;
	}
	increase();
	int index = hashCode(key);
	LinkedList* bucket = mBuckets[index];
	if(bucket == NULL) {
		bucket = new LinkedList();
		mBuckets[index] = bucket;
	}
	bucket->add(new Pair(key, value));
	mSize++;
}

Object* HashMap::get(Object *key)
{
	if(key == NULL) {
		return NULL;
	}
	int index = hashCode(key);
	LinkedList* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			Pair *pair = (Pair*)bucket->get(i);
			if(key->equals(pair->getLeft())) {
				return pair->getRight();
			}
		}
	}
	return NULL;
}

Object* HashMap::remove(Object *key)
{
	Object *target = NULL;
	if(key == NULL) {
		return target;
	}
	int index = hashCode(key);
	LinkedList* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			Pair *pair = (Pair*)bucket->get(i);
			if(key->equals(pair->getLeft())) {
				bucket->remove(i);
				target = pair->getRight();
				pair->removeRight();
				delete pair;
				mSize--;
				break;
			}
		}
	}
	return target;
}

bool HashMap::containsKey(Object *key)
{
	if(key == NULL) {
		return false;
	}
	int index = hashCode(key);
	LinkedList* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			Pair *pair = (Pair*)bucket->get(i);
			if(key->equals(pair->getLeft())) {
				return true;
			}
		}
	}
	return false;
}

bool HashMap::isEmpty()
{
	return (0 == mSize);
}

int HashMap::size()
{
	return mSize;
}

void HashMap::clear()
{
	for(int i = 0; i < mSize; i++) {
		LinkedList* bucket = mBuckets[i];
		if(bucket != NULL) {
			delete bucket;
		}
	}
	delete mBuckets;
	mSize = 0;
	mBucketSize = DEFAULT_SIZE_GRANULARITY;
	mBuckets = new LinkedList*[mBucketSize];
	memset(mBuckets, 0, sizeof(LinkedList*) * mBucketSize);
}

void HashMap::increase()
{
	if(mSize <= mBucketSize * 3 / 4) {
		return ;
	}

	ArrayList *list = new ArrayList();
	for(int i = 0; i < mBucketSize; i++) {
		LinkedList* bucket = mBuckets[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				Pair *pair = (Pair*)bucket->get(j);
				list->add(pair);
			}
			delete bucket;
		}
	}
	delete mBuckets;

	mBucketSize *= 2;
	mBuckets = new LinkedList*[mBucketSize];
	memset(mBuckets, 0, sizeof(LinkedList*) * mBucketSize);
	Iterator *iter = new Iterator(list);
	while(iter->hasNext()) {
		Pair *pair = (Pair*)iter->next();
		int index = hashCode(pair->getLeft());
		LinkedList* bucket = mBuckets[index];
		if(bucket == NULL) {
			bucket = new LinkedList();
			mBuckets[index] = bucket;
		}
		bucket->add(pair);
	}

	list->removeAll();
	delete list;
	delete iter;
}

void HashMap::decrease()
{
	if(mSize >= mBucketSize / 4) {
		return ;
	}
	if(mBucketSize <= DEFAULT_SIZE_GRANULARITY) {
		return ;
	}

	ArrayList *list = new ArrayList();
	for(int i = 0; i < mBucketSize; i++) {
		LinkedList* bucket = mBuckets[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				Pair *pair = (Pair*)bucket->get(j);
				list->add(pair);
			}
			delete bucket;
		}
	}
	delete mBuckets;

	mBucketSize /= 2;
	mBuckets = new LinkedList*[mBucketSize];
	memset(mBuckets, 0, sizeof(LinkedList*) * mBucketSize);
	Iterator *iter = new Iterator(list);
	while(iter->hasNext()) {
		Pair *pair = (Pair*)iter->next();
		int index = hashCode(pair->getLeft());
		LinkedList* bucket = mBuckets[index];
		if(bucket == NULL) {
			bucket = new LinkedList();
			mBuckets[index] = bucket;
		}
		bucket->add(pair);
	}

	list->removeAll();
	delete list;
	delete iter;
}

int HashMap::hashCode(Object *key)
{
	if(key == NULL) {
		return 0;
	}

	int h = key->hashCode();
	h %= mBucketSize;

	return h;
}
