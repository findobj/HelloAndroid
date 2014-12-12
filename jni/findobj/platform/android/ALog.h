#ifndef __ALOG_H__
#define __ALOG_H__

#include <android/log.h>

class ALog
{
public:
	static void i(const char *tag, const char *format, va_list ap);
	static void log(int prio, const char *tag, const char *format, va_list ap);
};

#endif
