#include <assert.h>
#include "files.h"
#define MAX_INPUT 500

typedef struct Unit		
{
	char *str;
	int (*cmp_fun)(char *);
	int (*operation_fun)(char * , char *);  
} Unit ;


/* date: 6.9
writer: Tzur
review: Mark
Status: approved
*/

void Print (int a)
{
    printf("%d |" , a);
}	


void Ex1 ()
{
    int i = 0;
    struct print_me
    {
      int number;
      void (*p)(int);
    };
    
    struct print_me arr[10];
    
    for( i = 0 ; i < 10 ;++i )
    {
    	arr[i].number = i;
    	arr[i].p = Print;
    }
    
     for( i = 0 ; i < 10 ;++i )
    {
    	(arr[i].p)(arr[i].number);
    }
 }
 
 /* date: 8.9
writer: Tzur
review: Roman
Status: approved
*/
 
int Remove(char *file ,char *dummy)
{
	(void)dummy;

 	if (0 == remove(file)) 
    {
        printf("The file is deleted successfully.\n");
        return SUCCESS;
    } 
    printf("Not found.\n");
    return REMOVE_FILE_ERROR;
 }
 
 
int Count(char *file , char *dummy)
{
 
 	FILE *file_p = NULL;
 	char ch = '.';
 	int count = 0;
 	(void)dummy;
 	
 	file_p = fopen(file , "r");
 	if (NULL == file_p) 
	{
    	return OPEN_FILE_ERROR;
    }
 	ch = getc(file_p);
	
	while(ch != EOF)
	{
		if('\n' == ch)
		{
			++count;
		}
		ch = getc(file_p);
	}
	
	fclose(file_p);
	
	printf("lines: %d " , count);
	
 	return SUCCESS;
 }
 
int Exit(char *file , char *str)
{
 	(void)file;
 	(void)str;
 	exit(1);
 	return SUCCESS;
}
 
 
int Append(char *file , char *str)
{
 	
 	FILE *file_p = fopen(file , "a");
 	assert(NULL != file);
 	assert(NULL != str);
	if (NULL == file_p) 
	{
    	return OPEN_FILE_ERROR;
    }

 	fputs(str , file_p);
 	fputs("\n" , file_p);
 
 	fclose(file_p);
 	
 	return SUCCESS;
}
 
int AppendBegin(char *filename, char *str)
{
	char *buffer ;
	long len_src = 0;
  	
    FILE *src = fopen(filename, "r");
	FILE *temp = fopen("temp_file", "w+");
	if (NULL == src) 
	{
    	return OPEN_FILE_ERROR;
    }
    if (NULL == temp) 
	{
    	return OPEN_FILE_ERROR;
    }
	
	fputs(str+1 , temp);					/* write to temp file */
	fputs("\n" , temp);
	
    len_src = ftell(src);
    rewind(src);							/* set the pointer to start */

    buffer = malloc(len_src);				/* copy src to temp */
    fread(buffer, 1, len_src, src);
    fwrite(buffer, 1, len_src, temp);
    free(buffer);

    fclose(src);
    remove(filename);

    fclose(temp);
    rename("temp_file", filename);
    printf("Append to the top.");
    
    return SUCCESS;
}


int RemoveCmp(char *str)
{
 	return(strcmp(str,"-remove"));
}
 
int CountCmp(char *str)
{
 	return(strcmp(str,"-count"));
}
 
int ExitCmp(char *str)
{
 
 	return(strcmp(str,"-exit"));
 	
}
 
int AppendBeginCmp(char *str)
{
 	if(*str == '<')
 	{
 		return SUCCESS;
 	}
 	return ERROR;
}
 
  
int AppendCmp(char *str)
{
 	(void)str;
 	return SUCCESS;
}
 
void ex2 ( char *filename)
{
	int status = SUCCESS;
	char input[MAX_INPUT];
	int i = 0;
	FILE *fp = NULL;
	
		
	Unit handler[5];
		
	handler[0].str = "-remove";
	handler[1].str = "-count";
	handler[2].str = "-exit";
	handler[3].str = "-beginLine";
	handler[4].str = "-append";
	
	handler[0].cmp_fun = RemoveCmp;
	handler[1].cmp_fun = CountCmp;
	handler[2].cmp_fun = ExitCmp;
	handler[3].cmp_fun = AppendBeginCmp;
	handler[4].cmp_fun = AppendCmp;
		
	handler[0].operation_fun = Remove;
	handler[1].operation_fun = Count;
	handler[2].operation_fun = Exit;
	handler[3].operation_fun = AppendBegin;
	handler[4].operation_fun = Append;
	
	printf("Enter somthing... \n");
	
	do
	{
		fp=fopen(filename , "a");
		scanf("%s", input);
		for(i = 0; i < 5; ++i)
		{
			if(0 == handler[i].cmp_fun(input))
			{	
				status = handler[i].operation_fun(filename, input); 
				break;
			}
		}
		fclose(fp);
	}
	while (status == SUCCESS);
}
 
 
 
 
 
   

