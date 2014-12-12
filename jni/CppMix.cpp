#include "CppMix.h"
#include "findobj/train/AStar.h"

/**
 * cpp mix entry
 */
int main_mix(void *data)
{
	AStar *astar = new AStar();
	astar->test();
	delete astar;

	return 0;
}
