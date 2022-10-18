#include <assert.h>					/*		assert			*/
#include <stddef.h>					/*		size_t			*/
#include <stdlib.h>					/*		malloc			*/
#include <stdio.h>					/*		printf			*/

#define TRUE 1
#define FALSE 0

typedef struct node						
{
	void *data;
	struct node *next;
}node_t;

void Test_Loop();
void Test_Flip();
void Test_Inter();
void NthFromLast();

/*****************************************************************************/
node_t *Insert(node_t *head, void *data)
{
	node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node -> data = data;
    
    head -> next = new_node;
    
    return new_node;
}


/*****************************************************************************/
/* Reverses the order of given slist.	*/

node_t *Flip(node_t *head)
{
    node_t *prev = NULL;
    node_t *current = head;
    node_t *next = NULL;
    
    while (current != NULL) 
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/****************************************************************************
* Tells whether a given slist has loop.										*
 * pseudo:																	*
 * ther are two pointers													*
 * one is run slow, skip to next node by one								*
 * second is run fast, skip two nodes										*
 * if the list is loop finally they will point to same node					*
 * if will point to null return false										*
*****************************************************************************/
int HasLoop(const node_t *head)
{
	node_t *slow = (node_t*)head;
	node_t *fast = (node_t*)head;
	
	while(NULL != slow && NULL != fast && NULL != fast -> next)
	{
		slow = slow -> next;
		fast = fast -> next -> next;
		
		if(slow == fast)
		{
			return TRUE;
		}
	}
	return FALSE;
}

/****************************************************************************/
/* Return a pointer to first node mutual to both slists, if any				*/
/****************************************************************************/
node_t *FindIntersection(node_t *head1, node_t *head2)
{
	while (head2) 
	{
		node_t* temp = head1;
		while (temp) 
		{
		    if (temp == head2)
		    {
		        return head2;
		    }
		    
			temp = temp -> next;
		}
		
		head2 = head2 -> next;
    }
}

/*****************************************************************************/
static void PrintList(node_t *list, size_t len)
{
	size_t i = 0;
	for(i = 1; i < len; ++i)
	{
		printf("%d -> ", *(int*)list->data);
		list = list -> next;
	}
	printf("%d\n", *(int*)list->data);
}

/****************************************************************************
 *									MAIN									*
 ****************************************************************************/

int main() 
{	
	
	Test_Loop();
	Test_Flip();
	Test_Inter();
	NthFromLast();
	
	return 0;
}

/****************************************************************************
 *									TESTS									*
 ****************************************************************************/
void Test_Loop()
{
	size_t i = 0;
	
	int arr[] = {1,2,3,4,5};
	size_t len = sizeof(arr)/sizeof (arr[0]);
	node_t *begin = (node_t*)malloc(sizeof(node_t));
	node_t *node = begin;
	
	
	begin -> data = &arr[0];
	for(i = 1; i < len; ++i)
	{
		node = Insert(node, &arr[i]);
	}
	
	
	HasLoop(begin)==TRUE ? printf("\nLoop\n") : printf("\nNo loop\n");
	PrintList(begin, len);
	

	node -> next = begin;
	HasLoop(begin)==TRUE ? printf("\nLoop\n") : printf("\nNo loop\n");
	PrintList(begin, len);
}

void Test_Flip()
{
	size_t i = 0;
	int arr[] = {1,2,3,4,5};
	size_t len = sizeof(arr)/sizeof (arr[0]);
	node_t *begin = (node_t*)malloc(sizeof(node_t));
	node_t *node = begin;
	
	
	begin -> data = &arr[0];
	for(i = 1; i < len; ++i)
	{
		node = Insert(node, &arr[i]);
	}
	
	begin = Flip(begin);
	printf("\nFlipped\n");
	PrintList(begin, len);
}

void Test_Inter()
{
	size_t i = 0;
	
	int arr[] = {1,2,2,3,4};
	size_t len = sizeof(arr)/sizeof (arr[0]);
	node_t *begin = (node_t*)malloc(sizeof(node_t));
	node_t *node = begin;
	node_t *print_runner = begin;
	node_t *inter_node = NULL;
	
	int arr2[] = {5,7,3,4};
	size_t len2 = sizeof(arr2)/sizeof (arr2[0]);
	node_t *begin2 = (node_t*)malloc(sizeof(node_t));
	node_t *node2 = begin2;
	node_t *print_runner2 = begin2;
	
	printf("\nList 1\n");
	begin -> data = &arr[0];
	for(i = 1; i < len; ++i)
	{
		node = Insert(node, &arr[i]);
	}
	PrintList(print_runner, len);
	
	
	printf("\nList 2\n");
	begin2 -> data = &arr2[0];
	for(i = 1; i < len2; ++i)
	{
		node2 = Insert(node2, &arr2[i]);
	}
	PrintList(print_runner2, len2);
	
	printf ("\ninter node:	%d\n" , &FindIntersection(begin,begin2)->data);
}

void NthFromLast()
{
   
	printf("nth\n");
	
}
