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

/*	approved by Slava 8.11.22					*/
size_t Strlen(const char *s)
{
	return ('\0' == *s) ? 0 : 1 + Strlen(s + 1);
}

/*	approved by Slava 8.11.22					*/
int Strcmp(const char *s1, const char *s2)
{
	if (*s1 == *s2 && '\0' == *s2)
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
	

	return Strcat(dest+1, src + 1);
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

/* Approved By Andrey 8.11.22	*/

/*	input	output:	
 *	| 4 |	| 4 |	SortStack[frame 1] -> not empty , pop 4 , 3 , 1 push -2,1,3,4		
 *	| 1 |	| 3	|	SortStack[frame 2] -> not empty , pop 4, 3 , push 1,3,4	*
 *	|-2 |	| 1 |	SortStack[frame 3] -> not empty , pop 4 , push 3,4		*
 *  | 3 |	|-2 |	SortStack[frame 4] -> is empty , push 4					*/

void SortedInsert(stack_t *stack, int value)
{
	int head_of_stack = 0;

	if (IsEmpty(stack) || value > *(int *)(Peek(stack)))
	{
		Push(stack, (void *)&value);
		return;
	}
	head_of_stack = *(int *)(Peek(stack));
	Pop(stack);
	SortedInsert(stack, value);
	Push(stack, (void *)&head_of_stack);
}

void SortStack(stack_t *stack)
{
	int head_of_stack = 0;

	if (!IsEmpty(stack))
	{
		head_of_stack = *(int *)(Peek(stack));
		Pop(stack);
		SortStack(stack);
		SortedInsert(stack, head_of_stack);
	}
}
