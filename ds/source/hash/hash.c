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

hash_t *Create(size_t table_size, compare_func_t cmp_func, action_func_t hash_func)
{
	hash_t *table = NULL;
	table = malloc(sizeof(hash_t));

	if (NULL == table)
	{
		return (NULL);
	}

	table->table_size = table_size;
	table->cmp_func = cmp_func;
	table->hash_func = hash_func;
}