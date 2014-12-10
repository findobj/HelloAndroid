#ifndef __TILE_H__
#define __TILE_H__

#include "Object.h"

class Tile : public Object
{
public:
	Tile(int index);
	virtual ~Tile();
public:
	int index;
};

#endif
