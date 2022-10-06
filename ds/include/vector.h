#include <stddef.h>					/*		size_t			*/
#ifndef __ILRD_CR02_VECTOR_H__
#define __ILRD_CR02_VECTOR_H__


typedef struct vector vector_t;


vector_t *VectorCreate(size_t capacity , size_t element_size);
/****************************************************************************
* Creates dynamic vector and returns pointer to memory address of new vector*
*																			*
* Parameters:																*
*	capacity     - number of elements in vector								*
*	element_size - size of element in bytes									*
*****************************************************************************/



void VectorDestroy(vector_t *vector);							
/****************************************************************************
* Frees dynamic vector memory												*
*																			*
* Parameters:																*
*	vector - pointer to memory address of vector, not NULL					*
*****************************************************************************/



void *VectorAccessElement(const vector_t *vector ,size_t index);	
/****************************************************************************
* Get value in dynamic vector by his index									*
*																			*
* Parameters:																*
*	vector	- pointer to memory address of vector, not NULL					*
*	index	- index of the value											*
*																			*
*****************************************************************************/



void VectorPush(vector_t *vector, const void *value);
/****************************************************************************
* Adds element to top of dynamic vector.									*
* If size reaches capacity after the push, doubles the capacity.			*
*																			*
* Parameters:																*
*	vector	- pointer to memory address of vector, not NULL					*
*	value	- pointer to element to be copied to vector, not NULL             *
*****************************************************************************/



void VectorPop(vector_t *vector);
/****************************************************************************
* Removes element from top of dynamic vector.								*
*																			*
* Parameters:																*
*	vector	- pointer to memory address of vector, not NULL					*
*																			*
* Warning: pop will result in undefined behavior if vector is empty!		*
*****************************************************************************/


size_t VectorSize(const vector_t *vector);
/****************************************************************************
* Returns current size of dynamic vector as size_t							*
*																			*
* Parameters:																*
*	vector	- pointer to memory address of vector, not NULL					*
*																			*
* Returns:																	*
*	current size of vector as size_t										*
*****************************************************************************/


size_t VectorCapacity(const vector_t *vector);
/****************************************************************************
* Returns dynamic vector capacity as size_t									*
*																			*
* Parameters:																*
*	vector	- pointer to memory address of vector, not NULL					*
*																			*
* Returns:																	*
*	current vector capacity as size_t										*
*****************************************************************************/


void VectorReserve(vector_t *vector,size_t value);
/****************************************************************************
* Increases dynamic vector capacity to requested capacity.					*
* If requested capacity is less than current capacity, does nothing.		*
*																			*
* Parameters:																*
*	vector	- pointer to memory address of vector, not NULL					*
*	value	- max number of elements in vector								*
*****************************************************************************/


void VectorShrink(vector_t *vector);
/****************************************************************************
* Decrease dynamic vector capacity to his size.								*
*																			*
* Parameters:																*
*	vector	- pointer to memory address of vector, not NULL					*
*****************************************************************************/




#endif


