#ifndef __STRING_H__
#define __STRING_H__

#include "Object.h"

class String : public Object
{
public:
	String();
	String(const char *data);
	virtual ~String();
public:
	virtual int length();
	virtual char charAt(int index);
	virtual char* toCharArray();
public:
	virtual bool equals(Object *obj);
	virtual int hashCode();
	virtual const char* whoAmI();
private:
	char *mData;
	int mLength;
private:
	static const char *S_KLASS;
};

#endif
