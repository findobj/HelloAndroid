#ifndef __TILE_H__
#define __TILE_H__

#include "findobj/Foundation.h"

class Tile : public Object
{
public:
	Tile(int index);
	virtual ~Tile();
public:
	int index;
};

#endif
