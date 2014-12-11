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
	Log::i("AppDelegate", "main start");

	AStar *astar = new AStar();
	astar->test();
	delete astar;

	Log::i("AppDelegate", "main end");
	return 0;
}

