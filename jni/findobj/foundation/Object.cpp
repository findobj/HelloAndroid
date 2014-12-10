#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

bool Object::equals(Object *obj)
{
	return (this == obj);
}
