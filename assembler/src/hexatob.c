#include "asm.h"

unsigned int hexatob(const char *ptr)
{
	unsigned int value;
	char ch;

	ch = *ptr;
	value = 0;

	while (ch == ' ' || ch == '\t')
		ch = *(++ptr);
	while (*ptr)
	{
		if (ch >= '0' && ch <= '9')
			value = (value << 4) + (ch - '0');
		else if (ch >= 'A' && ch <= 'F')
			value = (value << 4) + (ch - 'A' + 10);
		else if (ch >= 'a' && ch <= 'f')
			value = (value << 4) + (ch - 'a' + 10);
		else
			return value;
		ch = *(++ptr);
	}
	return (value);
}
