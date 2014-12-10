#ifndef __OBJECT_H__
#define __OBJECT_H__

class Object
{
public:
	Object();
	virtual ~Object();
public:
	virtual bool equals(Object *obj);
};

#endif
