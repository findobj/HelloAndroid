#include "Iterator.h"
#include <string.h>
#include "ArrayList.h"

Iterator::Iterator()
{
	list = new ArrayList();
	mIndex = 0;
}

Iterator::~Iterator()
{
	delete list;
}

bool Iterator::hasNext()
{
	return (mIndex < list->size());
}

Object* Iterator::next()
{
	return list->get(mIndex++);
}

void Iterator::put(Object *obj)
{
	if(obj == NULL) {
		return;
	}
	list->add(obj);
}

