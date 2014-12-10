#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include "Object.h"

class List;

class HashMap : public Object
{
public:
	HashMap();
	virtual ~HashMap();
public:
	virtual void put(char *key, Object *value);
	virtual Object* get(char *key);
	virtual void remove(char *key);
	virtual bool containsKey(char *key);
	virtual bool isEmpty();
	virtual int size();
	virtual void clear();
	virtual int hashCode(char *key);
protected:
	virtual void increase();
	virtual void decrease();
private:
	List **mBuckets;
	int mBucketSize;
	int mSize;
	static const int S_GRANULARITY;
};

#endif
