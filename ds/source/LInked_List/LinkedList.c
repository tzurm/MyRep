#include <assert.h>					/*		assert			*/
#include <stddef.h>					/*		size_t			*/
#include <stdlib.h>					/*		malloc			*/
#include <stdio.h>					/*		printf			*/
#include <string.h>					/*		memcpy			*/
#include "vector.h"					/*		my_vector		*/

#define MALLOC_CHECK(ptr) if(NULL == ptr) {return NULL;}
#define GROWTH_FACTOR 2
#define SHRINK_FACTOR 4
#define SIZE (vector -> capacity) * (vector -> element_size)

struct vector
{	
	void *array;					/*	point to array		*/
	size_t size;					/*	current size 		*/
	size_t capacity;				/*	max of the stack	*/
	size_t element_size;			/*	size of the element	*/
};


/*		approved by Roman 6.9.22		*/
vector_t *VectorCreate(size_t capacity , size_t element_size)
{
	
	vector_t *vector = (vector_t*)malloc(sizeof(vector_t));
	vector_t *array = malloc(capacity * element_size);
	
	if(0 == capacity)
	{
		return NULL;
	}
	
	MALLOC_CHECK(vector);
	
	if( NULL == array)
	{
		free(vector);
		return NULL;
	}
	
	vector -> array = array;
	vector -> element_size = element_size;
	vector -> capacity = capacity;
	vector -> size = 0;

	return(vector);

}

/*		approved by Roman 6.9.22		*/
void VectorDestroy(vector_t *vector)
{
	assert(NULL != vector);
	
	free(vector -> array);
	free(vector);
}

/*		approved by Roman 6.9.22		*/
void *VectorAccessElement(const vector_t *vector ,size_t index)
{
	assert(NULL != vector);
	
	return (char*)vector -> array + (index *(vector -> element_size));
	
}

/*		approved by Roman 6.9.22		*/
status VectorPush(vector_t *vector, const void *value)
{
	assert(NULL != vector);
	
	if(VectorSize(vector) == VectorCapacity(vector))
	{
		vector -> capacity *= GROWTH_FACTOR;
		VectorReserve(vector , vector -> capacity);
	}
	
	memcpy((char *)vector -> array + (vector-> size) * (vector -> element_size), value, vector -> element_size);
	
	++(vector-> size);
	
	return SUCCESS; 
}

/*		approved by Roman 6.9.22		*/
status VectorPop(vector_t *vector)
{
	assert(NULL != vector);
	
	--(vector-> size);
	
	/*	if size is quarter of capcity , capacity reduce by half */
	if(SHRINK_FACTOR*VectorSize(vector) < VectorCapacity(vector))
	{
		vector -> capacity /= 2;
		vector -> array = realloc(vector -> array, SIZE);
		
		return (NULL == vector -> array) ? REALLOC_ERROR : SUCCESS;
	}
	
	return SUCCESS;

}

/*		approved by Roman 6.9.22		*/
size_t VectorSize(const vector_t *vector)
{
	assert(NULL != vector);	
	
	return vector -> size;
}


/*		approved by Roman 6.9.22		*/
size_t VectorCapacity(const vector_t *vector)
{
	assert(NULL != vector);
	
	return vector -> capacity;
}

/*		approved by Roman 6.9.22		*/
status VectorReserve(vector_t *vector,size_t value)
{
	assert(NULL != vector);	
	
	if(value >  (vector -> capacity))
	{
		vector -> capacity = value;
		vector -> array = realloc(vector -> array, SIZE);
		
		return (NULL == vector -> array) ? REALLOC_ERROR : SUCCESS;
	}
	
	return SUCCESS;
}

/*		approved by Roman 6.9.22		*/
status VectorShrink(vector_t *vector)
{
	assert(NULL != vector);
	
	vector -> capacity = VectorSize(vector);
	vector -> array = realloc(vector -> array, SIZE);
	
	return (NULL == vector -> array) ? REALLOC_ERROR : SUCCESS;
}


