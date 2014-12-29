#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <stdio.h>
#include <string.h>

class Object
{
public:
	Object();
	virtual ~Object();
public:
	virtual bool equals(Object *obj);
	virtual int hashCode();
	virtual void retain();
	virtual void release();
public:
	static void assign(Object **pl, Object **pr);
public:
	virtual const char* whoAmI();
	virtual bool instanceOf(const char* className);
private:
	int mUseCount;
};

#endif
