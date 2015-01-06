#ifndef __TILE_H__
#define __TILE_H__

#include "findobj/Foundation.h"

class Tile : public Object
{
public:
	Tile(int index);
	Tile(int x, int y);
	virtual ~Tile();
public:
	virtual bool equals(Object *obj);
public:
	int index;
	int x;
	int y;
	int state;
};

#endif
