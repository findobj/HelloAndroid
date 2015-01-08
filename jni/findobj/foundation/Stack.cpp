#include "Stack.h"
#include "ArrayList.h"

Stack::Stack()
{
	mList = new ArrayList();
}

Stack::~Stack()
{
	if(mList != NULL) {
		mList->release();
	}
}

void Stack::push(Object *data)
{
	mList->add(data);
}

Object* Stack::pop()
{
	if(mList->size() <= 0) {
		return NULL;
	}
	Object *data = mList->get(mList->size() - 1);
	data->retain();
	mList->remove(mList->size() - 1);
	return data;
}

Object* Stack::peek()
{
	if(mList->size() <= 0) {
		return NULL;
	}
	Object *data = mList->get(mList->size() - 1);
	return data;
}

int Stack::size()
{
	return mList->size();
}
