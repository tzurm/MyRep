#ifndef __CR02_HASH_H__
#define __CR02_HASH_H__

typedef enum status
{
    NOT_EMPTY = 4,
    EMPTY = 3,
    FAIL_MALLOC = 2,
    FAIL = 1,
    SUCCESS = 0


} status_t;

typedef struct hash_table hash_t;
typedef int (*compare_func_t)(const void *data, void *param);
typedef int (*action_func_t)(void *data, void *param);
typedef size_t (*hash_func_t)(void *data);

hash_t *Create(size_t table_size, compare_func_t cmp_func, hash_func_t hash_func);

void Destroy(hash_t *table);

status_t Insert(hash_t *table, const void *key);

void Remove(hash_t *table, const void *key); /*if not found not my problem*/

void *Find(const hash_t *table, const void *key);

status_t ForEach(hash_t *table, action_func_t callback, const void *param);

size_t Count(const hash_t *table);

int IsEmpty(const hash_t *table);


#endif