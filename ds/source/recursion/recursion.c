#include <string.h> /*  strncmp */
#include <assert.h> /*	assert	*/
#include "recursion.h"

/*	0	1	2	3	4	5	6	7	8	9	10	*
 *	0	1	1	2	3	5	8	13	21	34	55	*/

/*	approved by Slava 8.11.22					*/
int Fibonacci(int element_index)
{
	if (1 >= element_index)
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

/*	approved by Slava 8.11.22					*/
size_t Strlen(const char *s)
{
	if ('\0' == *s)
		return 0;
	return 1 + Strlen(s + 1);
}

/*	approved by Slava 8.11.22					*/
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

/*	approved by Slava 8.11.22					*/

char *Strcpy(char *dest, const char *src)
{
	if ('\0' == *src)
	{
		*dest = '\0';
		return dest;
	}
	*dest = *src;
	Strcpy(dest + 1, src + 1);

	return dest;
}

/*	approved by Slava 8.11.22					*
 *	keep run on dest until get null terminator	*
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

/*	approved by Slava 8.11.22					*
 *	keep run on haystack until get null terminator	*
 *	find needle in haystack by strncmp				*
 *	repeat											*/
char *Strstr(char *haystack, const char *needle)
{
	if ('\0' == *haystack)
	{
		return NULL;
	}
	else if (0 == strncmp(haystack, needle, strlen(needle)))
	{
		return haystack;
	}

	return (Strstr(haystack + 1, needle));
}

/*	approved by Alex 8.11.22					*/
node_t *FlipList(node_t *node)
{
	node_t *flipped_node = NULL;
	assert(NULL != node);

	if (node->next == NULL)
	{
		return node;
	}
	flipped_node = FlipList(node->next);
	flipped_node->next = node;
	node->next = NULL;

	return node;
}
