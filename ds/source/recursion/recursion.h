#ifndef __ILRD_CR02_RECURSION__
#define __ILRD_CR02_RECURSION__

struct node
{
    void *data;
    struct node *next; /* address to next node    */
};

typedef struct node node_t;

int Fibonacci(int element_index);

/*
Node *FlipList(Node *node);
*/

size_t Strlen(const char *s);

int Strcmp(const char *s1, const char *s2);

char *Strcpy(char *dest, const char *src);

char *Strcat(char *dest, const char *src);

char *Strstr(char *haystack, const char *needle);

node_t *FlipList(node_t *node);

#endif