#ifndef __ILRD_CR02_RECURSION__
#define __ILRD_CR02_RECURSION__


struct stack
{
	char *stack_ptr;		/*	point to stack					*/
	size_t size;			/*	current size 					*/
	size_t capacity;		/*	max of the stack				*/
	size_t size_of_element; /*	size of the element, by value	*/
};
typedef struct stack stack_t;

struct node
{
    void *data;
    struct node *next; /* address to next node    */
};

typedef struct node node_t;

int Fibonacci(int element_index);

size_t Strlen(const char *s);

int Strcmp(const char *s1, const char *s2);

char *Strcpy(char *dest, const char *src);

char *Strcat(char *dest, const char *src);

char *Strstr(char *haystack, const char *needle);

node_t *FlipList(node_t *node);

void SortedInsert(stack_t *stack, int value);

void SortStack(stack_t *stack);


#endif
