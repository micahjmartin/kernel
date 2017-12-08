#include "string.h"

int strlen(const char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
	i = i + 1;
    }
    return i;
}

void string_reverse(char* str)
{
    int len = strlen(str) - 1;
    int i = 0;
    char a;
    char b;
    while(i < len-i)
    {
	a = str[i];
	b = str[len-i];
	str[i] = b;
	str[len-i] = a;
	i = i + 1;
    }
}

void itoc(int i, char* retval)
{
    int pos = 0;
    int base = 10;
    while(i > 0)
    {
	retval[pos] = '0' + (i % base);
	i = i / base;
	pos = pos + 1;
    }
    string_reverse(retval);
}
