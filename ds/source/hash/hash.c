#include <stdlib.h> /*		malloc			*/
#include <assert.h> /*		assert			*/
#include <stddef.h> /*		size_t			*/
#include <stdio.h>	/*		printf			*/

#include "hash.h"
#include "sll.h"

struct hash_table
{
	sll_t **list;
	compare_func_t cmp_func;
	hash_func_t hash_func;
	size_t table_size;
};
/*-------------------------Approved by ziv 15.11.2022-------------------------*/
hash_t *Create(size_t table_size, compare_func_t cmp_func, hash_func_t hash_func)
{
	hash_t *table = NULL;
	sll_t **array_of_list = NULL;
	size_t i = 0;

	table = (hash_t *)malloc(sizeof(hash_t));
	if (NULL == table)
	{
		return NULL;
	}

	array_of_list = (sll_t **)malloc(sizeof(sll_t *) * table_size);
	if (NULL == array_of_list)
	{
		free(table);
		return NULL;
	}

	table->table_size = table_size;
	table->cmp_func = cmp_func;
	table->hash_func = hash_func;
	table->list = array_of_list;

	for (i = 0; i < table_size; ++i)
	{
		*(table->list + i) = SLLCreate();
	}

	return table;
}
/*-------------------------Approved by Arie 16.11.2022-----------------------*/
void Destroy(hash_t *table)
{
	size_t i = 0;
	size_t size = 0;

	assert(NULL != table);

	size = table->table_size;

	for (i = 0; i < size; ++i)
	{
		SLLDestroy(*(table->list + i));
	}

	free(table->list);
	free(table);
}
/*-------------------------Approved by Arie 16.11.2022-----------------------*/
status_t Insert(hash_t *table, const void *key)
{
	sll_t *list = NULL;
	sll_iter_t iter = NULL;
	hash_func_t hash_func = NULL;
	void *copy_key = NULL;
	size_t hashed = 0;

	assert(NULL != table);
	assert(NULL != key);

	copy_key = (void *)key;
	hash_func = table->hash_func;
	hashed = hash_func(copy_key);
	list = *(table->list + hashed);
	iter = SLLEnd(list);
	SLLInsertBefore(iter, copy_key);

	return SUCCESS;
}
/*-------------------------Approved by Arie 16.11.2022-----------------------*/
void Remove(hash_t *table, const void *key) /*if not found not my problem*/	
{
	sll_t *list = NULL;
	sll_iter_t begin = NULL;
	sll_iter_t end = NULL;
	sll_iter_t iter = NULL;
	hash_func_t hash_func = NULL;	
	size_t hashed = 0;
	
	hash_func = table -> hash_func;
	
	hashed = hash_func((void*)key);
	list = *(table -> list + hashed);
	
	begin = SLLBegin(list);
	end = SLLBegin(list);
	
	iter = SLLFind(table->cmp_func, begin, end, (void*)key);
	SLLRemove(iter);
}
 
/*-------------------------Approved by Ziv 16.11.2022-----------------------*/
void *Find(const hash_t *table, const void *key)
{
	size_t index_found = 0;
	sll_iter_t iter = NULL;
	sll_t *key_list = NULL;

	assert(NULL != table);
	assert(NULL != key);

	index_found = (table->hash_func)((void *)key);
	key_list = *(table->list + index_found);
	iter = SLLFind(table->cmp_func, SLLBegin(key_list), SLLEnd(key_list),
				   (void *)key);

	return SLLGetData(iter);
}
/*-------------------------Approved by Arie 16.11.2022-----------------------*/
status_t ForEach(hash_t *table, action_func_t callback, const void *param)
{
	size_t i = 0;
	sll_t *list = NULL;
	size_t size = 0;
	sll_iter_t begin = NULL;
	sll_iter_t end = NULL;

	size = table->table_size;
	
	for (i = 0; i < size; ++i)
	{
		list = *(table -> list + i);
		begin = SLLBegin(list);
		end = SLLEnd(list);
		
		SLLForEach(callback, begin, end, (void *)param);  	
	}
	return SUCCESS;
}	

/*-------------------------Approved by Roman 16.11.2022----------------------*/
size_t Count(const hash_t *table)
{
	size_t count_inuse = 0;
	size_t i = 0;
	size_t table_size = 0;
	sll_t *list = NULL;

	assert(NULL != table);

	table_size = table->table_size;

	for (i = 0; i < table_size; ++i)
	{
		list = *(table->list + i);
		count_inuse += SLLCount(list) - 1;
	}

	return count_inuse;
}
int IsEmpty(const hash_t *table)
{
	if (0 == Count(table))
	{
		return EMPTY;
	}
	return NOT_EMPTY;
}
