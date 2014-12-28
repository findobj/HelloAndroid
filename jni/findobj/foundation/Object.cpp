#include "Object.h"

Object::Object()
{
	mClassName = whoAmI();
	retain();
}

Object::~Object()
{
}

bool Object::equals(Object *obj)
{
	return (this == obj);
}

int Object::hashCode()
{
	unsigned long h = 0, g;
	void *address = (void*)this;
	int len = sizeof(void*);
	char *keyStart = (char*)address;
	char *keyEnd = keyStart + len;

	while (keyStart < keyEnd) {
		h = (h << 4) + *keyStart++;
		if ((g = (h & 0xF0000000))) {
			h = h ^ (g >> 24);
			h = h ^ g;
		}
	}

	return h;
}

void Object::retain()
{
	mUseCount++;
}

void Object::release()
{
	mUseCount--;
	if(mUseCount <= 0) {
		delete this;
	}
}

void Object::assign(Object **pl, Object **pr)
{
	if(pl == NULL ||
			pr == NULL) {
		return;
	}
	if(*pl == *pr) {
		return;
	}
	if(*pl != NULL) {
		(*pl)->release();
	}
	*pl = *pr;
	if(*pl != NULL) {
		(*pl)->retain();
	}
}

const char* Object::whoAmI()
{
	return NULL;
}

bool Object::instanceOf(const char* className)
{
	if(mClassName != NULL &&
			className != NULL) {
		return (0 == strcmp(mClassName, className));
	}
	return false;
}

