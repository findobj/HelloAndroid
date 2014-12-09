#include "CppMix.h"
#include "findobj/component/AppDelegate.h"

/**
 * cpp mix entry
 */
int main_mix(void *data)
{
	AppDelegate *app = new AppDelegate();
	int ret = app->main();
	delete app;

	return ret;
}
