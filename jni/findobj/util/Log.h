#ifndef __LOG_H__
#define __LOG_H__

#include <android/log.h>

class Log
{
public:
	static void i(const char *tag, const char *format, ...);
	static void log(int prio, const char *tag, const char *format, va_list ap);
};

#endif
