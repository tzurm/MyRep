#include <stdio.h>		/* printf,*/
#include <stdlib.h>		/* malloc */
#include <assert.h>		
#include <string.h>	

/* h file */
typedef struct handler
{
    void *data;
    int (*print)(void *);
    int (*add)(void *, int);
    int (*free_heap)(void *);

} handler;

enum status 
{
	SUCCESS,
	ERROR
};


/****************************************************************************/
/*									PRINT									*/
/****************************************************************************/

int PrintInt(void* data)
{
	printf(" %d " , *(int*)&(data));
	return SUCCESS;
}

int PrintFloat(void* data)
{
	printf(" %.3f " , *(float*)&(data));
	return SUCCESS;
}

int PrintString(void* data)
{
	printf(" %s \n" , (char*)(data));
	return SUCCESS;
}


/****************************************************************************/
/*									ADD										*/
/****************************************************************************/


int AddInt(void *data, int input)
{	
	
	*(int*)&data += input;
	
	return SUCCESS;
}

int AddFloat(void *data, int input)
{
	*(float*)&data += *(float*)&input;
	return SUCCESS;
}

int AddString(void *data , int input)
{
	 size_t len_data = strlen(data);
	 size_t len_input = strlen((char*)&input);
	 char *buffer = malloc(len_data + len_input);
	 
	 buffer = strcat(data, (char*)&input);
	 if(NULL == buffer)
	 {
	 	printf("Error!");
	 }
	 data = buffer;
	 free(buffer);
	 return SUCCESS;
}

/****************************************************************************/
/*									FREE									*/
/****************************************************************************/

static int FreeDummy(void* data)
{
	data=data;
	return SUCCESS;
}

static int FreeHeap(void* data)
{
	data=data;
	free(data);
	return SUCCESS;
}

/****************************************************************************/
/*								init MultiArrayElemnts						*/
/****************************************************************************/

static int InitArray(handler *arr)
{

	*(int*)&arr[0].data = 3;
	arr[0].print = PrintInt;
	arr[0].add = AddInt;
	arr[0].free_heap = FreeDummy;

	*(float*)&arr[1].data = 3.3;
	arr[1].print = PrintFloat;
	arr[1].add = AddFloat;
	arr[1].free_heap = &FreeDummy;

	
	arr[2].data = "Three";
	arr[2].print = PrintString;
	arr[2].add = AddString;
	arr[2].free_heap = FreeHeap;
	
	return SUCCESS;
} 

/****************************************************************************/
/*						print,add,free array								*/
/****************************************************************************/

int PrintArr(handler* arr ,size_t len)
{
	size_t i = 0;
	
	for( i = 0; i < len; ++i)
	{
		(*arr[i].print)(arr[i].data);
	}
	
	return SUCCESS;
}

int AddArr(handler* arr ,size_t len , int input)
{
	size_t i = 0;
	
	for( i = 0; i < 2; ++i)
	{
		(*arr[i].add)((arr[i].data),input);
	}
	
	return SUCCESS;
}

int FreeArr(handler* arr ,size_t len)
{
	size_t i = 0;
	
	for( i = 0; i < 2; ++i)
	{
		(*arr[i].free_heap)(arr[i].data);
	}
	
	return SUCCESS;
}




void MultiArrayElemnts()
{

	int input = 10;
	handler arr[5];
	
	InitArray(arr);
	PrintArr(arr, 3);
	AddArr(arr, 3 , input); 		/* 	not working	*/
	/*	FreeArr(arr, 3);	 */
	PrintArr(arr, 3);
	
	printf("\nall done\n");
	
}




int main() 
{
	
    MultiArrayElemnts();
    

    return 0;
}
