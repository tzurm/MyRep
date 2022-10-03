#include <assert.h>					/*		assert			*/
#include <stddef.h>					/*		size_t			*/
#include <stdlib.h>					/*		malloc			*/
#include <stdio.h>					/*		printf			*/
#include <string.h>					/*		memcpy			*/
#include "vector.h"					/*		my_vector		*/

#define MALLOC_CHECK(ptr) if(NULL == ptr) {return NULL;}

struct vector
{	
	void *array;					/*	point to array		*/
	size_t size;					/*	current size 		*/
	size_t capacity;				/*	max of the stack	*/
	size_t size_of_element;			/*	size of the element	*/
};

vector_t *VectorCreate(size_t capacity , size_t size_of_elemnet)
{
	vector_t *hold_vector = malloc(sizeof(vector_t));
	vector_t -> array = malloc(capacity * size_of_elemnet);
	MALLOC_CHECK(hold_vector);
	MALLOC_CHECK(vector_t -> array);
	
	hold_vector -> element_size = size_of_elemnet;
	hold_vector -> capacity = capacity;
	hold_vector -> size = 0;

	return(hold_vector);

}
/*
void VectorDestroy(vector_t *vector)
{

}

void *VectorAccessElement(const vector_t *vector ,size_t index);
{

}

void VectorPush(vector_t *vector, const void *value)
{

}

void VectorPop(vector_t *vector)
{

}
*/

size_t VectorSize(const vector_t *vector);
{
	assert(NULL != vector);	
	
	return vector -> size;
}

size_t VectorCapacity(const vector_t *vector)
{
	assert(NULL != vector);
	
	return vector -> capacity;
}

/*
void VectorReserve(vector_t *vector,size_t value)

void VectorShrink(vector_t *vector)
*/
