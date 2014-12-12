#include "ALog.h"

void ALog::i(const char *tag, const char *format, va_list ap)
{
	log(ANDROID_LOG_INFO, tag, format, ap);
}

void ALog::log(int prio, const char *tag, const char *format, va_list ap)
{
	__android_log_vprint(prio, tag, format, ap);
}
