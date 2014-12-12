#ifndef __LLOG_H__
#define __LLOG_H__

#include <stdarg.h>

class LLog
{
public:
	static void i(const char *tag, const char *format, va_list ap);
	static char* stringFormat(const char *format, va_list ap);
};

#endif
