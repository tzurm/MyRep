#ifndef __BST_H__
#define __BST_H__

typedef struct node node_t;
typedef struct bst bst_t;

typedef enum status
{
	FAIL_MALLOC = 2,
	FAIL = 1,
	SUCCESS = 0

} status_t;

typedef enum traversal
{
	PRE_ORDER = 0,
	POST_ORDER = 1,
	IN_ORDER = 2
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

void *Find(bst_t *bst, void *data);

size_t CountNodes(bst_t *bst);

int ForEach(bst_t *bst, ActionFunc_t ActionFunc_t, void *param, int traversal_type);

int ForEachIn(bst_t *bst, ActionFunc_t ActionFunc, void *param, int traversal_type);
int ForEachPre(bst_t *bst, ActionFunc_t ActionFunc, void *param, int traversal_type);
int ForEachPost(bst_t *bst, ActionFunc_t ActionFunc, void *param, int traversal_type);

bst_t *Remove(bst_t *bst, void *key);
void *FindMin(bst_t *bst);

#endif
