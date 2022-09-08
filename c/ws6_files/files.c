#include "files.h"
#include <assert.h>

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
 
    


void Remove(char *file)
 {
 
 	if (remove(file) == 0) 
    {
        printf("The file is deleted successfully.\n");
    } 
    else 
    {
        printf("Not found.\n");
    }
    
 }
 
 
 int Count(char *file)
 {
 
 	FILE *file_p = NULL;
 	char ch = '.';
 	int count=0;
 	
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
	
 	return count;
 }
 
 void Append (char *file , char *str)
 {
 	FILE *file_p = NULL;
 	file_p = fopen(file , "a");
 	
 	fputs("\n" , file_p);
 	fputs(str , file_p);
 	
 	fclose(file_p);
 }
 
 void TopLine(const char *filename, const char *str)
{
  	char *buffer ;
  	long len_src = 0;
  	
    FILE *src = fopen(filename, "r");		/* open src file   */
    FILE *temp = fopen("temp_file", "w+");	/* open temp file  */
	
    fwrite(str, 1, strlen(str), temp);		/* write to temp file */

    fseek(src, 0L, SEEK_END);				/* size of src and */
    len_src = ftell(src);
    rewind(src);							/* set the pointer to start */

    buffer = malloc(len_src);					/* copy src to temp */
    fread(buffer, 1, len_src, src);
    fwrite(buffer, 1, len_src, temp);
    free(buffer);
 
    fclose(src);
    remove(filename);

    fclose(temp);
    rename("temp_file", filename);
}


