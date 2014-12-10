#include "HashMap.h"
#include <string.h>
#include "List.h"
#include "AB.h"
#include "Iterator.h"

const int HashMap::S_GRANULARITY = 4;

HashMap::HashMap()
{
	mSize = 0;
	mBucketSize = S_GRANULARITY;
	mBuckets = new List*[mBucketSize];
	memset(mBuckets, 0, sizeof(List*) * mBucketSize);
}

HashMap::~HashMap()
{
	for(int i = 0; i < mBucketSize; i++) {
		List* bucket = mBuckets[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				AB *ab = (AB*)bucket->get(j);
				delete (Object*)ab->b;
			}
			delete bucket;
		}
	}
	delete mBuckets;
}

void HashMap::put(char *key, Object *value)
{
	if(key == NULL ||
			value == NULL) {
		return ;
	}
	increase();
	int index = hashCode(key);
	List* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			AB *ab = (AB*)bucket->get(i);
			char *tmp = (char*)ab->a;
			if(0 == strcmp(tmp, key)) {
				bucket->remove(i);
				break;
			}
		}
	} else {
		bucket = new List();
		mBuckets[index] = bucket;
	}
	bucket->add(new AB((void*)key, (void*)value));
	mSize++;
}

Object* HashMap::get(char *key)
{
	if(key == NULL) {
		return NULL;
	}
	int index = hashCode(key);
	List* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			AB *ab = (AB*)bucket->get(i);
			char *tmp = (char*)ab->a;
			if(0 == strcmp(tmp, key)) {
				return (Object*)ab->b;
			}
		}
	}
	return NULL;
}

void HashMap::remove(char *key)
{
	if(key == NULL) {
		return ;
	}
	int index = hashCode(key);
	List* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			AB *ab = (AB*)bucket->get(i);
			char *tmp = (char*)ab->a;
			if(0 == strcmp(tmp, key)) {
				bucket->remove(i);
				mSize--;
				break;
			}
		}
	}
}

bool HashMap::containsKey(char *key)
{
	if(key == NULL) {
		return false;
	}
	int index = hashCode(key);
	List* bucket = mBuckets[index];
	if(bucket != NULL) {
		for(int i = 0; i < bucket->size(); i++) {
			AB *ab = (AB*)bucket->get(i);
			char *tmp = (char*)ab->a;
			if(0 == strcmp(tmp, key)) {
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
		List* bucket = mBuckets[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				AB *ab = (AB*)bucket->get(j);
				delete (Object*)ab->b;
			}
			delete bucket;
		}
	}
	delete mBuckets;
	mSize = 0;
	mBucketSize = S_GRANULARITY;
	mBuckets = new List*[mBucketSize];
	memset(mBuckets, 0, sizeof(List*) * mBucketSize);
}

void HashMap::increase()
{
	if(mBucketSize >= mSize / 2) {
		return ;
	}
	Iterator iter;
	for(int i = 0; i < mBucketSize; i++) {
		List* bucket = mBuckets[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				AB *ab = (AB*)bucket->get(j);
				AB *tmp = new AB(ab->a, ab->b);
				iter.put(tmp);
			}
			delete bucket;
		}
	}
	delete mBuckets;

	mBucketSize *= 2;
	mBuckets = new List*[mBucketSize];
	memset(mBuckets, 0, sizeof(List*) * mBucketSize);
	while(iter.hasNext()) {
		AB *ab = (AB*)iter.next();
		char *key = (char*)ab->a;
		int index = hashCode(key);
		List* bucket = mBuckets[index];
		if(bucket == NULL) {
			bucket = new List();
			mBuckets[index] = bucket;
		}
		bucket->add(ab);
	}
}

void HashMap::decrease()
{
	if(mBucketSize <= mSize / 2) {
		return ;
	}
	if(mBucketSize <= S_GRANULARITY) {
		return ;
	}
	Iterator iter;
	for(int i = 0; i < mBucketSize; i++) {
		List* bucket = mBuckets[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				AB *ab = (AB*)bucket->get(j);
				AB *tmp = new AB(ab->a, ab->b);
				iter.put(tmp);
			}
			delete bucket;
		}
	}
	delete mBuckets;
	mBucketSize /= 2;
	mBuckets = new List*[mBucketSize];
	memset(mBuckets, 0, sizeof(List*) * mBucketSize);
	while(iter.hasNext()) {
		AB *ab = (AB*)iter.next();
		char *key = (char*)ab->a;
		int index = hashCode(key);
		List* bucket = mBuckets[index];
		if(bucket == NULL) {
			bucket = new List();
			mBuckets[index] = bucket;
		}
		bucket->add(ab);
	}
}

int HashMap::hashCode(char *key)
{
	if(key == NULL) {
		return 0;
	}

	int len = strlen(key);
	unsigned long h = 0, g;
	char *keyStart = key;
	char *keyEnd = key + len;

	while (keyStart < keyEnd) {
		h = (h << 4) + *keyStart++;
		if ((g = (h & 0xF0000000))) {
			h = h ^ (g >> 24);
			h = h ^ g;
		}
	}

	h %= mBucketSize;

	return h;
}
