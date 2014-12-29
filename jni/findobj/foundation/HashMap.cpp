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
			bucket->release();
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

void HashMap::remove(Object *key)
{
	if(key == NULL) {
		return ;
	}
	int index = hashCode(key);
	LinkedList* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			Pair *pair = (Pair*)bucket->get(i);
			if(key->equals(pair->getLeft())) {
				bucket->remove(i);
				mSize--;
				decrease();
				break;
			}
		}
	}
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
			bucket->release();
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
			bucket->release();
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

	list->release();
	iter->release();
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
			bucket->release();
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

	list->release();
	iter->release();
}

int HashMap::hashCode(Object *key)
{
	if(key == NULL) {
		return 0;
	}

	int h = key->hashCode();
	h = h & (mBucketSize - 1);

	Log::i("HashMap", "lih hashCode: %d", h);

	return h;
}
