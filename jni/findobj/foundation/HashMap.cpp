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
	increase();
	int index = hashCode(key);
	LinkedList* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			Pair *pair = (Pair*)bucket->get(i);
			if(key->equals(pair->left)) {
				bucket->remove(i);
				mSize--;
				break;
			}
		}
	} else {
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
			if(key->equals(pair->left)) {
				return pair->right;
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
			if(key->equals(pair->left)) {
				bucket->remove(i);
				mSize--;
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
			if(key->equals(pair->left)) {
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
	Iterator iter;
	for(int i = 0; i < mBucketSize; i++) {
		LinkedList* bucket = mBuckets[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				Pair *pair = (Pair*)bucket->get(j);
				Pair *tmp = new Pair(pair->left, pair->right);
				pair->left = NULL;
				pair->right = NULL;
				iter.put(tmp);
			}
			delete bucket;
		}
	}
	delete mBuckets;

	mBucketSize *= 2;
	mBuckets = new LinkedList*[mBucketSize];
	memset(mBuckets, 0, sizeof(LinkedList*) * mBucketSize);
	while(iter.hasNext()) {
		Pair *pair = (Pair*)iter.next();
		int index = hashCode(pair->left);
		LinkedList* bucket = mBuckets[index];
		if(bucket == NULL) {
			bucket = new LinkedList();
			mBuckets[index] = bucket;
		}
		bucket->add(pair);
	}
}

void HashMap::decrease()
{
	if(mSize >= mBucketSize / 4) {
		return ;
	}
	if(mBucketSize <= DEFAULT_SIZE_GRANULARITY) {
		return ;
	}
	Iterator iter;
	for(int i = 0; i < mBucketSize; i++) {
		LinkedList* bucket = mBuckets[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				Pair *pair = (Pair*)bucket->get(j);
				Pair *tmp = new Pair(pair->left, pair->right);
				pair->left = NULL;
				pair->right = NULL;
				iter.put(tmp);
			}
			delete bucket;
		}
	}
	delete mBuckets;

	mBucketSize /= 2;
	mBuckets = new LinkedList*[mBucketSize];
	memset(mBuckets, 0, sizeof(LinkedList*) * mBucketSize);
	while(iter.hasNext()) {
		Pair *pair = (Pair*)iter.next();
		int index = hashCode(pair->left);
		LinkedList* bucket = mBuckets[index];
		if(bucket == NULL) {
			bucket = new LinkedList();
			mBuckets[index] = bucket;
		}
		bucket->add(pair);
	}
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
