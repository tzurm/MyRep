#include <stdio.h>	/*   size_t */
#include <string.h> /*  strncmp    */
#include "recursion.h"

#define TRUE 1
#define FALSE 0

/*0	1	1	2	3	5	8	13	21	34	55	*
 *0	1	2	3	4	5	6	7	8	9	10	*/

int Fibonacci(int element_index)
{
	if (2 >= element_index)
	{
		return element_index;
	}
	return Fibonacci(element_index - 1) + Fibonacci(element_index - 2);
}
/*
Node *FlipList(Node *node)
{
}
*/

size_t Strlen(const char *s)
{
	if ('\0' == *s)
		return 0;
	return 1 + Strlen(s + 1);
}

int Strcmp(const char *s1, const char *s2)
{
	if (*s1 == *s2 && *s2 == '\0')
	{
		return *s1 - *s2;
	}
	if (*s1 == *s2)
	{
		return Strcmp(s1 + 1, s2 + 1);
	}
	return *s1 - *s2;
}

/*	approved by 								*/

char *Strcpy(char *dest, const char *src)
{
	if ('\0' == *src)
	{
		return dest;
	}
	*dest = *src;
	Strcpy(dest + 1, src + 1);

	return dest;
}

/*	approved by 								*/
/*	keep run on dest until get null terminator	*
 *	start copy from src to dest					*/
char *Strcat(char *dest, const char *src)
{
	if ('\0' == *src)
	{
		return dest;
	}
	while ('\0' != *dest)
	{
		++dest;
	}
	*dest = *src;
	++dest;

	return Strcat(dest, src + 1);
}

/*	approved by 									*/
/*	keep run on haystack until get null terminator	*
 *	find needle in haystack by strncmp				*
 *	repeat											*/
char *Strstr(char *haystack, const char *needle)
{
	char *runner = NULL;
	runner = haystack;

	if ('\0' == *runner)
	{
		return NULL;
	}
	else if (0 == strncmp(runner, needle, strlen(needle)))
	{
		return runner;
	}

	return (Strstr(runner + 1, needle));
}