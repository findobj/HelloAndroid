#include "Queue.h"
#include "ArrayList.h"

Queue::Queue()
{
	mList = new ArrayList();
}

Queue::~Queue()
{
	if(mList != NULL) {
		mList->release();
	}
}

void Queue::enqueue(Object *data)
{
	mList->add(data);
}

Object* Queue::dequeue()
{
	if(mList->size() <= 0) {
		return NULL;
	}
	Object *data = mList->get(0);
	data->retain();
	mList->remove(0);
	return data;
}

Object* Queue::peek()
{
	if(mList->size() <= 0) {
		return NULL;
	}
	Object *data = mList->get(0);
	return data;
}

int Queue::size()
{
	return mList->size();
}

