#include "AB.h"

AB::AB()
{
}

AB::AB(Object *a, Object *b)
{
	this->a = a;
	this->b = b;
}

AB::~AB()
{
	if(a != NULL) {
		delete a;
	}
	if(b != NULL) {
		delete b;
	}
}

