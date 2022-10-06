#include <stdio.h>
#include <stddef.h>
#include "vector.h"					/*		my_vector		*/


void Test_1();
void Test_2_Shrink();
void VectorPrint(vector_t *vector);


int main() 
{
   
	printf("\n******	Test_1	******\n\n");
	
	Test_1();
	
	
	printf("\n******	Test_2_Shrink (resize capacity by pop)	******\n\n");
	
	Test_2_Shrink();
	
	
	
	
	return 0;
}


void Test_1()
{
	int value[] ={3,6,9,278};
	vector_t *vector = VectorCreate(1 ,4);
	
	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPrint(vector);
	
	VectorPush(vector,&value[0]);
	VectorPush(vector,&value[1]);
	VectorPush(vector,&value[1]);
	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPrint(vector);
	
	VectorPush(vector,&value[1]);
	
	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPrint(vector);
	
	VectorPush(vector,&value[2]);
	
	/*************************************************************************/
	printf("\n*			VectorReserve test when index < size			*\n");
	
	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPrint(vector);
	printf("\n");
	
	
	VectorReserve(vector,2);
	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPrint(vector);
	
	/*************************************************************************/
	printf("\n*				Shrink test							*\n");
	VectorShrink(vector);
	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	
	
	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPrint(vector);
	printf("\n");
	
	VectorPop(vector);
	
	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPrint(vector);
	printf("\n");
	/*************************************************************************/

}

void Test_2_Shrink()
{
	int value[] ={3,6,9,278};
	vector_t *vector = VectorCreate(1 ,4);
	
	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPush(vector,&value[1]);
	VectorPush(vector,&value[2]);

	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorReserve(vector,16);
	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPop(vector);
	printf("\nSTATUS:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
}

void VectorPrint(vector_t *vector)
{
	size_t i = 0;	
	/*
	for(i = 0 ; i < VectorCapacity(vector) ; ++i)
	{
		printf("%d | ", *(int*)VectorAccessElement(vector,i));
	}
	
	printf("\n");*/
	for(i = 0 ; i < VectorSize(vector) ; ++i)
	{
		printf("%d | ", *(int*)VectorAccessElement(vector,i));
	}
}



