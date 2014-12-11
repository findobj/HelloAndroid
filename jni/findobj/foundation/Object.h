#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <stdio.h>
#include <string.h>

class Object
{
public:
	Object();
	Object(char *klass);
	virtual ~Object();
public:
	virtual bool equals(Object *obj);
	virtual int hashCode();
	virtual char* klass();
private:
	char *mKlass;
};

#endif
