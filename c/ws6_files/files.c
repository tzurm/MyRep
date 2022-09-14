#include <assert.h>
#include "files.h"
#define MAX_INPUT 500

struct unit		
{
	char *str;
	int (*cmp_fun)(char *);
	int (*operation_fun)(char * , char *);  
};


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
    } 
    else 
    {
        printf("Not found.\n");
        return REMOVE_FILE_ERROR;
    }
    
    return SUCCESS;
 }
 
 
int Count(char *file , char *dummy)
{
 	
 	FILE *file_p = NULL;
 	char ch = '.';
 	int count = 0;
 	(void)dummy;
 	
 	file_p = fopen(file , "r");
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
	if(file_p == NULL)
		return ERROR;
	

 	fputs(str , file_p);
 	fputs("\n" , file_p);
 	
 	fclose(file_p);
 	
 	return SUCCESS;
}
 
int AppendBegin(char *filename, char *str)
{
	char *buffer ;
	long len_src = 0;
  	
    FILE *src = fopen(filename, "r");		/* open src file   */
    FILE *temp = fopen("temp_file", "w+");	/* open temp file  */
	
	fputs(str+1 , temp);					/* write to temp file */
	fputs("\n" , temp);
	
    fseek(src, 0, SEEK_END);				/* size of src and */
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
	
		
	struct  unit handler[5];
		
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
			if(0 == handler[i].cmp_fun(input))	 /* cmp function */
			{	
				status = handler[i].operation_fun(filename, input); /* start fun */
				break;
			}
			
		}

		fclose(fp);
	}
	while (status == SUCCESS);
}
 
 
 
 
 
   

