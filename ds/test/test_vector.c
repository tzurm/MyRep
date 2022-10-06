#include <stdio.h>
#include <stddef.h>
#include "vector.h"					/*		my_vector		*/


void Test_Create();
void Test_Reserve();
void Test_Shrink();
void Test_ShrinkByPop();
void PrintVector(vector_t *vector);


int main() 
{
   
	printf("\n\n****************	Test_Create&push	**************\n");
	Test_Create();
	
	printf("\n\n****************	Test_Reserve		**************\n");
	Test_Reserve();
	
	printf("\n\n****************	Test_Shrink		**************\n");
	Test_Shrink();
	
	printf("\n\n****************	Test_ShrinkByPop	**************\n");
	Test_ShrinkByPop();
	
	return 0;
}


void Test_Create()
{
	int value[] ={3,6,9,278};
	vector_t *vector = VectorCreate(20 ,4);
	
	printf("\nSize:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPush(vector,&value[0]);
	VectorPush(vector,&value[1]);
	VectorPush(vector,&value[1]);
	printf("\nSize:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPush(vector,&value[1]);
	printf("\nSize:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPush(vector,&value[2]);
	printf("\nSize:	%ld / %ld\n\n",VectorSize(vector),VectorCapacity(vector));
	PrintVector(vector);
	
	VectorDestroy(vector);

}

void Test_Reserve()
{
	vector_t *vector = VectorCreate(20 ,4);
	
	printf("\nSize:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	printf("\n");
	printf("\nsend 2 as capacity");
	VectorReserve(vector,2);
	printf("\nSize:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	printf("\nsend 5 as capacity");
	VectorReserve(vector,5);
	printf("\nSize:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));

	
	VectorDestroy(vector);
	
}

void Test_Shrink()
{
	int value[] ={3,6,9,278};
	vector_t *vector = VectorCreate(2 ,4);	
	
	printf("\nSize:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPush(vector,&value[1]);
	printf("\nSize:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorShrink(vector);
	printf("\nSize:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	printf("\n");
	
	VectorDestroy(vector);
	
}

void Test_ShrinkByPop()
{
	int value[] ={3,6,9,278};
	vector_t *vector = VectorCreate(16 ,4);
	
	VectorPush(vector,&value[2]);
	VectorPush(vector,&value[2]);
	VectorPush(vector,&value[2]);
	VectorPush(vector,&value[2]);
	printf("\nSize:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	VectorPop(vector);
	printf("\nSize:	%ld / %ld\n",VectorSize(vector),VectorCapacity(vector));
	
	VectorDestroy(vector);
	
}

void PrintVector(vector_t *vector)
{
	size_t i = 0;	
	/*
	for(i = 0 ; i < VectorCapacity(vector) ; ++i)
	{
		printf("%d | ", *(int*)VectorAccessElement(vector,i));
	}*/
	
	printf("\n");
	for(i = 0 ; i < VectorSize(vector) ; ++i)
	{
		printf("%d | ", *(int*)VectorAccessElement(vector,i));
	}
}



