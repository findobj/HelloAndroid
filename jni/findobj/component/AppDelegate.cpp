#include "AppDelegate.h"
#include "findobj/util/Util.h"
#include "findobj/foundation/AStar.h"

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

int AppDelegate::main()
{
	Log::i("AppDelegate", "main");
	AStar *astar = new AStar();
	astar->test();
	delete astar;

	return 0;
}

