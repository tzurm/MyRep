#include <stdio.h>		/* printf,*/
#include <stdlib.h>		/* malloc */
#include <assert.h>		
#include <string.h>	

typedef struct handler
{
    void *data;
    void (*print)(void *);
    void (*add)(void *, int);
    void (*free_heap)(void *);

} handler;


/**********************************************/

static void *PrintInt(void* data)
{
	printf("%d" , (int)(data));
}

static void *PrintFloat(void* data)
{
	printf("%f" , (float*)(data));
}

static void *PrintString(void* data)
{
	printf("%s" , (char*)(data));
}

/**********************************************/

void *AddInt(void* data, int input)
{
	input += (int)data ;
	data = (void*)input;
}

void *AddFloat(void* data, int input)
{
	(float)input += (float)data ;
	data = (void*)input;
}

void *AddString(void* data , int input)
{
	 size_t len_data = strlen(data);
	 char temp=(char)input;
	 size_t len_input = strlen(temp);
	 char *buffer = malloc(len_data + len_input);
	 
	 *buffer = strcat(data, temp);
	 if(NULL == buffer)
	 {
	 	printf("Error!");
	 }
	 *data = *buffer;
	 free(buffer);
}

/**********************************************/

void *FreeDummy(void* data)
{
	void(*data);
}

void *FreeHeap(void* data)
{
	void(*data);
	free(*data);
}

/**********************************************/

int init_struct()
{

handler arr[3];

arr[0].data = 3;
arr[0].print = PrintInt;
arr[0].add = AddInt;
arr[0].free_heap = FreeDummy;


arr[1].data = 3.3;
arr[1].print = PrintFloat;
arr[1].add = AddFloat;
arr[1].free_heap = FreeDummy;


arr[2].data = "Three";
arr[2].print = PrintString;
arr[2].add = AddString;
arr[2].free_heap = FreeHeap;

}



int main() 
{
    init_struct();
    

    return 0;
}
