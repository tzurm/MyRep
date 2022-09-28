#include <stdio.h>		/* printf,*/
#include <stdlib.h>		/* malloc */
#include <assert.h>		
#include <string.h>		/*strlen */
#define SIZE 100
#define LEN 3
/* ziv aprroved */

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
	SUCCESS ,
	ERROR
} ;


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
	printf(" %.2f " , *(float*)&(data));
	
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
	*(int*)data += input;

	
	return SUCCESS;
}

int AddFloat(void *data, int input)
{
	
	*(float*)data += input;
	
	return SUCCESS;
}
 /*ziv: need to change to struct */ 
int AddString(void *data , int input)
{
	char *buffer=NULL;
	char user_input[SIZE] = { 0 };
	size_t len_data = strlen(data);
	
	sprintf(user_input, "%d", input);
	len_data += strlen(user_input) + 1;
	buffer = realloc(data, len_data);
	/* buffer = (char*)malloc(len_data); */
	if(NULL == buffer)
	 {
	 	return ERROR;
	 }

	buffer = strcat(data, user_input);
    data = buffer;
    
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
	free(data);
	return SUCCESS;
}

/****************************************************************************/
/*								init MultiArrayElemnts						*/
/****************************************************************************/

static int InitInt(handler *arr)
{
	char str[6] = {0};
	str[0] = 't' ;
	str[1] = 'h' ;
	str[2] = 'r' ;
	str[3] = 'e' ;
	str[4] = 'e' ;
	str[5] = '\0';
	
	
	*(int*)&arr[0].data = 3;
	arr[0].print = PrintInt;
	arr[0].add = AddInt;
	arr[0].free_heap = FreeDummy;

	*(float*)&arr[1].data = 3.3;
	arr[1].print = PrintFloat;
	arr[1].add = AddFloat;
	arr[1].free_heap = FreeDummy;

	
	arr[2].data = str;
	arr[2].print = PrintString;
	arr[2].add = AddString;
	arr[2].free_heap = FreeHeap;
	
	return SUCCESS;
} 

/****************************************************************************/
/*						print,add,free array								*/
/****************************************************************************/

int PrintArr(handler *arr ,size_t len)
{
	size_t i = 0;
	
	for( i = 0; i < len; ++i)
	{
		arr[i].print(arr[i].data);
	}
	
	return SUCCESS;
}

int AddArr(handler *arr ,size_t len , int input)
{
	
	size_t i = 0;
	
	len=len;
	for( i = 0; i < 2; ++i)
	{
		arr[i].add(&arr[i].data,input);
	}
	
	return SUCCESS;
}


int FreeArr(handler *arr ,size_t len)
{
	size_t i = 0;
	
	for( i = 0; i < len; ++i)
	{
		arr[i].free_heap(&arr[i].data);
	}
	
	return SUCCESS;
}



void MultiArrayElemnts()
{

	int input = 10;
	handler arr[LEN];
	
	InitArray(arr);
	PrintArr(arr, LEN);
	AddArr(arr, LEN, input); 
	
	/*FreeArr(arr, LEN); */
	PrintArr(arr, LEN);
	
	printf("\nall done\n");
	
}



int main() 
{
	
    MultiArrayElemnts();
    

    return 0;
}
