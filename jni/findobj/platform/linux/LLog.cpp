#include "LLog.h"
#include <string.h>
#include <stdio.h>

void LLog::i(const char *tag, const char *format, va_list ap)
{
	char* result = LLog::stringFormat(format, ap);
	printf("%s: %s\n", tag, result);
	delete result;
}

char* LLog::stringFormat(const char *format, va_list ap)
{
	char *result = strdup(format);
	int i;
	for (i = 0; i < strlen(result); i++) {
		if (result[i] == '%' &&
				i + 1 < strlen(result)) {
			switch(result[i+1]) {
				case 'd': {
					int arg = va_arg(ap, int);
					int lenTmp = strlen(result) + sizeof(int) * 8;
					char *resultLeft = new char[lenTmp + 1];
					memset(resultLeft, 0, lenTmp + 1);
					memcpy(resultLeft, result, i + 2);
					char *resultTmp = new char[lenTmp + 1];
					memset(resultTmp, 0, lenTmp);
					sprintf(resultTmp, resultLeft, arg);
					int tmpI = strlen(resultTmp) - 1;
					if(i + 2 < strlen(result)) {
						memcpy(resultTmp + strlen(resultTmp), result + i + 2, strlen(result) - i - 2);
					}
					char *tmp2 = result;
					result = resultTmp;
					delete tmp2;
					i = tmpI;
					break;
				}
				case 's': {
					char *arg = va_arg(ap, char*);
					int lenTmp = strlen(result) + strlen(arg);
					char *resultLeft = new char[lenTmp + 1];
					memset(resultLeft, 0, lenTmp + 1);
					memcpy(resultLeft, result, i + 2);
					char *resultTmp = new char[lenTmp + 1];
					memset(resultTmp, 0, lenTmp);
					sprintf(resultTmp, resultLeft, arg);
					int tmpI = strlen(resultTmp) - 1;
					if(i + 2 < strlen(result)) {
						memcpy(resultTmp + strlen(resultTmp), result + i + 2, strlen(result) - i - 2);
					}
					char *tmp2 = result;
					result = resultTmp;
					delete tmp2;
					i = tmpI;
					break;
				}
				case '%': {
					i++;
					break;
				}
				default:
					break;
			}
		}
	}
	return result;
}
