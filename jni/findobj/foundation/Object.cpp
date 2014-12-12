#include "Object.h"

Object::Object()
{
	mKlass = NULL;
}

Object::Object(char *klass)
{
	mKlass = klass;
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

char* Object::klass()
{
	return mKlass;
}
