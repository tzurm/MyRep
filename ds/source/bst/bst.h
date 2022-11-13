#ifndef __BST_H__
#define __BST_H__

typedef struct node node_t;
typedef struct bst bst_t;

typedef enum status
{
	FAIL = 1,
	SUCCESS = 0

} status_t;

typedef enum traversal
{
	pre_order = 0,
	post_order = 1,
	in_order = 2
} traversal_t;

typedef enum child
{
	Right = 1,
	Left = 0
} child_t;

typedef int (*CompareFunc_t)(const void *data, void *param);
typedef int (*ActionFunc_t)(void *data, void *param);

bst_t *Create(CompareFunc_t CompareFunc);

void Destroy(bst_t *bst);

status_t Insert(bst_t *bst, void *data);

void *Find(bst_t *tree, void *data);

size_t CountNodes(bst_t *tree);

int ForEach(bst_t *bst, int ActionFunc_t(), void *param, int traversal_type);

#endif
