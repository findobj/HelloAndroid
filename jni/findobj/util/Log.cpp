#include "Log.h"
#include <string.h>
#include "Config.h"
#include "findobj/Platform.h"

#ifdef PLATFORM_ANDROID
#include "findobj/platform/android/ALog.h"
#endif
#ifdef PLATFORM_LINUX
#include "findobj/platform/linux/LLog.h"
#endif

const int Log::PRIO_INFO = 1;

void Log::i(const char *tag, const char *format, ...)
{
	va_list argp;
	va_start(argp, format);
	char *decorFormat = new char[strlen(format) + 128];
	strcpy(decorFormat, "lih ");
	strcat(decorFormat, format);
	log(PRIO_INFO, tag, decorFormat, argp);
	va_end(argp);
}

void Log::log(int prio, const char *tag, const char *format, va_list ap)
{
	if(Config::DEBUG) {

#ifdef PLATFORM_ANDROID
		if(PRIO_INFO == prio) {
			ALog::i(tag, format, ap);
		}
#endif

#ifdef PLATFORM_LINUX
		if(PRIO_INFO == prio) {
			LLog::i(tag, format, ap);
		}
#endif

	}
}
