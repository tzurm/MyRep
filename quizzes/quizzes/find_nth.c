#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void push(Node **head_ref, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printNthFromLast(Node *head, size_t n)
{
    static size_t i = 0;

    if (NULL == head)
    {
        return;
    }
    printNthFromLast(head->next, n);
    ++i;

    if (i == n)
    {
        printf("%d\n", head->data);
    }
}

int main()
{
    struct Node *head = NULL;

    /* 35->15->4->20 */
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);

    printNthFromLast(head, 4);

    return 0;
}