#include "Log.h"
#include "Config.h"

void Log::i(const char *tag, const char *format, ...)
{
	va_list argp;
	va_start(argp, format);
	log(ANDROID_LOG_INFO, tag, format, argp);
	va_end(argp);
}

void Log::log(int prio, const char *tag, const char *format, va_list ap)
{
	if(Config::DEBUG) {
		__android_log_vprint(prio, tag, format, ap);
	}
}
