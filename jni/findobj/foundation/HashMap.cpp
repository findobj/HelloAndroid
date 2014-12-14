#include "HashMap.h"
#include <string.h>
#include "Constant.h"
#include "ArrayList.h"
#include "AB.h"
#include "Iterator.h"
#include "findobj/Util.h"

HashMap::HashMap()
{
	mSize = 0;
	mBucketSize = DEFAULT_SIZE_GRANULARITY;
	mBuckets = new ArrayList*[mBucketSize];
	memset(mBuckets, 0, sizeof(ArrayList*) * mBucketSize);
}

HashMap::~HashMap()
{
	for(int i = 0; i < mBucketSize; i++) {
		ArrayList* bucket = mBuckets[i];
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
	ArrayList* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			AB *ab = (AB*)bucket->get(i);
			if(key->equals(ab->a)) {
				bucket->remove(i);
				break;
			}
		}
	} else {
		bucket = new ArrayList();
		mBuckets[index] = bucket;
	}
	bucket->add(new AB(key, value));
	mSize++;
}

Object* HashMap::get(Object *key)
{
	if(key == NULL) {
		return NULL;
	}
	int index = hashCode(key);
	ArrayList* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			AB *ab = (AB*)bucket->get(i);
			if(key->equals(ab->a)) {
				return ab->b;
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
	ArrayList* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			AB *ab = (AB*)bucket->get(i);
			if(key->equals(ab->a)) {
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
	ArrayList* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			AB *ab = (AB*)bucket->get(i);
			if(key->equals(ab->a)) {
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
		ArrayList* bucket = mBuckets[i];
		if(bucket != NULL) {
			delete bucket;
		}
	}
	delete mBuckets;
	mSize = 0;
	mBucketSize = DEFAULT_SIZE_GRANULARITY;
	mBuckets = new ArrayList*[mBucketSize];
	memset(mBuckets, 0, sizeof(ArrayList*) * mBucketSize);
}

void HashMap::increase()
{
	if(mSize <= mBucketSize * 3 / 4) {
		return ;
	}
	Iterator iter;
	for(int i = 0; i < mBucketSize; i++) {
		ArrayList* bucket = mBuckets[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				AB *ab = (AB*)bucket->get(j);
				AB *tmp = new AB(ab->a, ab->b);
				ab->a = NULL;
				ab->b = NULL;
				iter.put(tmp);
			}
			delete bucket;
		}
	}
	delete mBuckets;

	mBucketSize *= 2;
	mBuckets = new ArrayList*[mBucketSize];
	memset(mBuckets, 0, sizeof(ArrayList*) * mBucketSize);
	while(iter.hasNext()) {
		AB *ab = (AB*)iter.next();
		int index = hashCode(ab->a);
		ArrayList* bucket = mBuckets[index];
		if(bucket == NULL) {
			bucket = new ArrayList();
			mBuckets[index] = bucket;
		}
		bucket->add(ab);
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
		ArrayList* bucket = mBuckets[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				AB *ab = (AB*)bucket->get(j);
				AB *tmp = new AB(ab->a, ab->b);
				ab->a = NULL;
				ab->b = NULL;
				iter.put(tmp);
			}
			delete bucket;
		}
	}
	delete mBuckets;

	mBucketSize /= 2;
	mBuckets = new ArrayList*[mBucketSize];
	memset(mBuckets, 0, sizeof(ArrayList*) * mBucketSize);
	while(iter.hasNext()) {
		AB *ab = (AB*)iter.next();
		int index = hashCode(ab->a);
		ArrayList* bucket = mBuckets[index];
		if(bucket == NULL) {
			bucket = new ArrayList();
			mBuckets[index] = bucket;
		}
		bucket->add(ab);
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
