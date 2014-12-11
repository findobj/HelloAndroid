#include "AppDelegate.h"
#include "findobj/Util.h"
#include "findobj/train/AStar.h"

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

int AppDelegate::main()
{
	AStar *astar = new AStar();
	astar->test();
	delete astar;

	return 0;
}

