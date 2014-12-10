#include "HashMap.h"
#include <string.h>
#include "List.h"
#include "AB.h"
#include "Iterator.h"

const int HashMap::S_GRANULARITY = 4;

HashMap::HashMap()
{
	mSize = 0;
	mCapacity = S_GRANULARITY;
	mMap = new List*[mCapacity];
	memset(mMap, 0, sizeof(List*) * mCapacity);
}

HashMap::~HashMap()
{
	for(int i = 0; i < mSize; i++) {
		List* bucket = mMap[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				AB *ab = (AB*)bucket->get(j);
				delete (Object*)ab->b;
			}
		}
		delete bucket;
	}
	delete mMap;
}

void HashMap::put(char *key, Object *value)
{
	if(key == NULL ||
			value == NULL) {
		return ;
	}
	increase();
	int index = hashCode(key);
	List* bucket = mMap[index];
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
		mMap[index] = bucket;
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
	List* bucket = mMap[index];
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
	List* bucket = mMap[index];
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
	List* bucket = mMap[index];
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
		List* bucket = mMap[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				AB *ab = (AB*)bucket->get(j);
				delete (Object*)ab->b;
			}
		}
		delete bucket;
	}
	delete mMap;
	mSize = 0;
	mCapacity = S_GRANULARITY;
	mMap = new List*[mCapacity];
	memset(mMap, 0, sizeof(List*) * mCapacity);
}

void HashMap::increase()
{
	if(mCapacity <= mSize / 2) {
		return ;
	}
	mCapacity *= 2;
	Iterator iter;
	for(int i = 0; i < mSize; i++) {
		List* bucket = mMap[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				AB *ab = (AB*)bucket->get(j);
				AB *tmp = new AB(ab->a, ab->b);
				iter.put(tmp);
			}
		}
		delete bucket;
	}
	delete mMap;
	mMap = new List*[mCapacity];
	memset(mMap, 0, sizeof(List*) * mCapacity);
	while(iter.hasNext()) {
		AB *ab = (AB*)iter.next();
		put((char*)ab->a, (Object*)ab->b);
	}
}

void HashMap::decrease()
{
	if(mCapacity >= mSize / 2) {
		return ;
	}
	if(mCapacity <= S_GRANULARITY) {
		return ;
	}
	mCapacity /= 2;
	Iterator iter;
	for(int i = 0; i < mSize; i++) {
		List* bucket = mMap[i];
		if(bucket != NULL) {
			for(int j = 0; j < bucket->size(); j++) {
				AB *ab = (AB*)bucket->get(j);
				AB *tmp = new AB(ab->a, ab->b);
				iter.put(tmp);
			}
		}
		delete bucket;
	}
	delete mMap;
	mMap = new List*[mCapacity];
	memset(mMap, 0, sizeof(List*) * mCapacity);
	while(iter.hasNext()) {
		AB *ab = (AB*)iter.next();
		put((char*)ab->a, (Object*)ab->b);
	}
}

int HashMap::hashCode(char *key)
{
	return 0;
}
