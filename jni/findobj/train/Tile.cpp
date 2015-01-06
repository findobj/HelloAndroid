#include "Tile.h"

Tile::Tile(int index)
{
	this->index = index;
	x = 0;
	y = 0;
}

Tile::Tile(int x, int y)
{
	this->x = x;
	this->y = y;
	index = 0;
}

Tile::~Tile()
{
}

bool Tile::equals(Object *obj)
{
	if(obj != NULL) {
		Tile *tile = (Tile*)obj;
		if(index == tile->index &&
				x == tile->x &&
				y == tile->y) {
			return true;
		}
	}
	return false;
}
