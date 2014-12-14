#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include "Object.h"

class ArrayList;

class HashMap : public Object
{
public:
	HashMap();
	virtual ~HashMap();
public:
	virtual void put(Object *key, Object *value);
	virtual Object* get(Object *key);
	virtual void remove(Object *key);
	virtual bool containsKey(Object *key);
	virtual bool isEmpty();
	virtual int size();
	virtual void clear();
protected:
	virtual void increase();
	virtual void decrease();
	virtual int hashCode(Object *key);
private:
	ArrayList **mBuckets;
	int mBucketSize;
	int mSize;
};

#endif
