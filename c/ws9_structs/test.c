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
}


/****************************************************************************/
/*									PRINT									*/
/****************************************************************************/

int PrintInt(void* data)
{
	printf("%d" , *(int*)&(data));
	return SUCCESS;
}

int PrintFloat(void* data)
{
	printf("%f" , *(float*)&(data));
	return SUCCESS;
}

int PrintString(void* data)
{
	printf("%s" , (char*)(data));
	return SUCCESS;
}


/****************************************************************************/
/*									ADD										*/
/****************************************************************************/


int *AddInt(void* data, int input)
{	
	*(int*)&data += *(int*)&input;
}

int *AddFloat(void* data, int input)
{
	*(float*)&data += *(float*)&input;
}

int *AddString(void* data , int input)
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
}

/****************************************************************************/
/*									FREE									*/
/****************************************************************************/

static int *FreeDummy(void* data)
{
	data=data;
	return SUCCESS;
}

static int *FreeHeap(void* data)
{
	data=data;
	free(data);
	return SUCCESS;
}

/****************************************************************************/
/*									MultiArrayElemnts						*/
/****************************************************************************/

void MultiArrayElemnts()
{
	int status = SUCCESS;
	int input = 5;
	
	handler arr[3]={0};

	*(int*)&arr[1].data = 3;
	arr[0].print = PrintInt;
	arr[0].add = AddInt;
	arr[0].free_heap = FreeDummy;

	*(float*)&arr[1].data = 3.3;
	arr[1].print = PrintFloat;
	arr[1].add = AddFloat;
	arr[1].free_heap = &FreeDummy;

	*(char**)&arr[2].data = "Three";
	arr[2].print = PrintString;
	arr[2].add = AddString;
	arr[2].free_heap = FreeHeap;

	
	printf("input : %d" ,input);


	
}




int main() 
{
	
    MultiArrayElemnts();
    

    return 0;
}
